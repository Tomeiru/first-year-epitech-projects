/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** falling particle particles
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "elements/entities/particles/falling_particle.h"

falling_particle_t *falling_particle_create(sfVector2f pos,
sfVector2u size, sfColor color)
{
    falling_particle_t *particle = (falling_particle_t*)
    buffer_create(sizeof(falling_particle_t), pos, size);
    float step_size = size.x / 17;
    float start_pos = step_size / 2;

    if (!particle)
        return (NULL);
    particle->update = &falling_particle_update;
    for (int i = 0; i < 16; i++) {
        particle->p_pos[i] = (sfVector2f) {start_pos +
        step_size * i + rand() % ((int) step_size),
        -(rand() % START_HEIGHT)};
        particle->p_acc_y[i] = 0;
    }
    particle->color = color;
    return (particle);
}

void falling_particle_update(entity_t *entity, infos_t *infos, float elapsed)
{
    falling_particle_t *particle = (falling_particle_t*) entity;

    UNUSED(infos);
    buffer_clear((buffer_t*) entity);
    for (int i = 0; i < 16; i++) {
        if (particle->p_pos[i].y <= particle->size.y) {
            particle->p_acc_y[i] += FALL_SPEED * elapsed;
            particle->p_pos[i].y += particle->p_acc_y[i];
        } else {
            particle->p_acc_y[i] = 0;
            particle->p_pos[i].y = -(rand() % START_HEIGHT);
        }
        falling_particle_draw_particle(particle, particle->p_pos[i]);
    }
}

void falling_particle_draw_particle(falling_particle_t *particle,
sfVector2f pos)
{
    if (pos.y - 1 < 0 || pos.y + 1 >= particle->size.y)
        return;
    for (int y_offset = -1; y_offset < 2; y_offset++) {
        for (int x_offset = -1; x_offset < 2; x_offset++) {
            buffer_put_pixel((buffer_t*) particle, particle->color,
            (sfVector2u) {pos.x + x_offset, pos.y + y_offset});
        }
    }
}