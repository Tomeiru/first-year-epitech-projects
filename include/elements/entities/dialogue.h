/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** dialogue.h
*/

#ifndef DIALOGUE_H_
#define DIALOGUE_H_

#include "elements/entities/entity.h"

typedef struct dialogue_s {
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
    sfText *text;
    float time;
    char *text_str;
    int end;
    char temp;
} dialogue_t;

#endif /* !DIALOGUE_H_ */