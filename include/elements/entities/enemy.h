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
    sfVector2f pos_start;
    int health;
    int move_status;
} enemy_t;

enemy_t *enemy_create(size_t size, infos_t *infos, sfVector2f pos);
void enemy_horizontal_update(entity_t *entity, infos_t *infos, float elapsed);
void enemy_vertical_update(entity_t *entity, infos_t *infos, float elapsed);


#endif /* !ENEMY_H_ */
