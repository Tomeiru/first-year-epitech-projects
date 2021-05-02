/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** projectile
*/

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "elements/entities/entity.h"

typedef struct projectile_s {
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
    float speed;
} projectile_t;

projectile_t *projectile_create(sfVector2f pos,
float rot, float speed, sfTexture *texture);
void projectile_update(entity_t *entity, infos_t *infos, float elapsed);

#endif /* !PROJECTILE_H_ */
