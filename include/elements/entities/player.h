/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "elements/entities/entity.h"
#include "map.h"

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
    float health;
    float max_health;
    float speed;
    direction_t dir;
    float anim;
    char can_move;
} player_t;

player_t *player_create(infos_t *infos);
void player_update(entity_t *entity, infos_t *infos, float elapsed);
void player_move_update(player_t *player, map_t *map, float elapsed);

#endif /* !PLAYER_H_ */
