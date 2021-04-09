/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** buffer
*/

#ifndef BUFFER_H_
#define BUFFER_H_

#include "elements/entities/entity.h"

typedef struct buffer_s {
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
    sfVector2u size;
    sfUint8 *pixels;
} buffer_t;


#endif /* !BUFFER_H_ */
