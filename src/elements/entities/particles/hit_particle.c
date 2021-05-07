/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** hit particle
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "elements/entities/particles/hit_particle.h"

hit_particle_t *hit_particle_create(element_t *attach)
{
    sfVector2f pos = {attach->pos.x - 32, attach->pos.y - 32};
    hit_particle_t *hit_particle = (hit_particle_t*)
    buffer_create(sizeof(hit_particle_t), pos, (sfVector2u) {64, 96});

    if (!hit_particle)
        return (NULL);
    sfSprite_setPosition(hit_particle->sprite, pos);
    hit_particle->hitbox = (sfIntRect) {-1, -1, 0, 0};
    hit_particle->update = &hit_particle_update;
    hit_particle->attach = attach;
    hit_particle->time = 0;
    for (int i = 0; i < 6; i++) {
        hit_particle->particles[i] =
        (sfVector2f) {28 + 8 * (i % 2), 8 + (i / 2) * 8};
        hit_particle->acc[i] =
        (sfVector2f) {3 * (1 + 2 * ((-i - 1) % 2)), 0.2};
    }
    return (hit_particle);
}

void hit_particle_update(entity_t *entity, infos_t *infos, float elapsed)
{
    hit_particle_t *hit_particle = (hit_particle_t*) entity;
    char update = 0;

    hit_particle->time += elapsed;
    buffer_clear((buffer_t*) hit_particle);
    for (int i = 0; i < 6; i++) {
        hit_particle->acc[i].x = hit_particle->acc[i].x * (0.9 + (rand() % 10) * 0.1);
        hit_particle->acc[i].y += hit_particle->acc[i].y;
        hit_particle->particles[i].x += hit_particle->acc[i].x;
        hit_particle->particles[i].y += hit_particle->acc[i].y;
        update |= draw_hit_particle(hit_particle, hit_particle->particles[i]);
    }
    if (!update)
        scene_remove_element(infos->scene, (element_t*) entity, 1);
}

int draw_hit_particle(hit_particle_t *hit_particle, sfVector2f particle)
{
    int update = 0;

    for (int y = -2; y < 3; y++) {
        for (int x = -2; x < 3; x++) {
            if (particle.x + x < 0 || particle.x + x >= 96
            || particle.y + y < 0 || particle.y + y >= 96)
                continue;
            buffer_put_pixel((buffer_t*) hit_particle, HIT_COLOR,
            (sfVector2u) {particle.x + x, particle.y + y});
            update = 1;
        }
    }
    return (update);
}
