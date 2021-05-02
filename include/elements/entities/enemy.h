/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** enemy
*/

#ifndef ENEMY_H_
#define ENEMY_H_

#include "elements/entities/entity.h"

typedef struct enemy_s {
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
    int health;
} enemy_t;

enemy_t *enemy_create(infos_t *infos);

#endif /* !ENEMY_H_ */
