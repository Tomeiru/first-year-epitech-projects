/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** entity
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include "elements/element.h"

typedef struct entity_s {
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
    void (*update)(struct entity_s *entity, infos_t *infos, float elapsed);
} entity_t;

typedef void (*update_entity_fct_t)(entity_t *entity, infos_t *infos, float);

#endif /* !ENTITY_H_ */
