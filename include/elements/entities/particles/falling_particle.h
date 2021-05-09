/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** falling particle
*/

#ifndef FALLING_PARTICLE_H_
#define FALLING_PARTICLE_H_

#include "elements/entities/buffer.h"

#define START_HEIGHT 100
#define FALL_SPEED 0.1

typedef struct falling_particle_s {
    element_type_t type;
    sfVector2f pos;
    float rot;
    sfIntRect hitbox;
    sfSprite *sprite;
    move_element_fct_t move;
    rotate_element_fct_t rotate;
    draw_element_fct_t draw;
    on_click_fct_t on_click;
    get_infos_element_fct_t get_infos;
    destroy_element_fct_t destroy;
    update_entity_fct_t update;
    sfVector2u size;
    sfUint8 *pixels;
    sfTexture *texture;
    char edited;
    sfColor color;
    sfVector2f p_pos[16];
    float p_acc_y[16];
} falling_particle_t;

falling_particle_t *falling_particle_create(sfVector2f pos,
sfVector2u size, sfColor color);
void falling_particle_update(entity_t *entity, infos_t *infos, float elapsed);
void falling_particle_draw_particle(falling_particle_t *particle,
sfVector2f pos);

#endif /* !FALLING_PARTICLE_H_ */
