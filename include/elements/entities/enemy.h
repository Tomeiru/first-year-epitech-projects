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
    void (*attack)(struct enemy_s *enemy, infos_t *infos);
    void (*pattern)(struct enemy_s *enemy,
    sfVector2f *move, infos_t *infos, float speed);
    sfVector2f pos_start;
    float health;
    float speed;
    int move_status;
    float attack_cooldown;
    direction_t dir;
    float anim;
    float damage_time;
} enemy_t;

typedef void (*attack_enemy_fct_t)(enemy_t *enemy, infos_t *infos);
typedef void (*pattern_enemy_fct_t)(enemy_t *enemy,
sfVector2f *move, infos_t *infos, float speed);

enemy_t *enemy_create(size_t size, infos_t *infos, sfVector2f pos);
void enemy_horizontal_update(entity_t *entity, infos_t *infos, float elapsed);
void enemy_vertical_update(entity_t *entity, infos_t *infos, float elapsed);
void enemy_ranged_attack(enemy_t *enemy, infos_t *infos);
void enemy_close_attack(enemy_t *enemy, infos_t *infos);

void enemy_vertical_pattern(enemy_t *enemy,
sfVector2f *move, infos_t *infos, float speed);
void enemy_horizonthal_pattern(enemy_t *enemy,
sfVector2f *move, infos_t *infos, float speed);

#endif /* !ENEMY_H_ */
