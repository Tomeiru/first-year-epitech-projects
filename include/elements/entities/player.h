/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "elements/entities/entity.h"

typedef struct player_s {
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
    char can_move;
} player_t;

player_t *player_create(infos_t *infos);
void player_update(entity_t *entity, infos_t *infos, float elapsed);

#endif /* !PLAYER_H_ */
