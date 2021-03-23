/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** particle
*/

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "elements/entities/entity.h"

typedef struct particle_s {
    element_type_t type;
    sfVector2f pos;
    float rot;
    sfIntRect hitbox;
    sfSprite *sprite;
    move_element_fct_t move;
    rotate_element_fct_t rotate;
    draw_element_fct_t draw;
    on_click_fct_t on_click;
    set_infos_element_fct_t set_infos;
    destroy_element_fct_t destroy;
    update_entity_fct_t update;
    float time;
    float life_time;
    int sprite_speed;
} particle_t;

particle_t *particle_create(sfVector2f pos, float rot,
sfTexture *texture, float life_time);
void particle_default_update(entity_t *entity, infos_t *infos, float elapsed);

#endif /* !PARTICLE_H_ */
