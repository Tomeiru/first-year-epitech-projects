/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** enemy_patterns
*/

#include "my_rpg.h"
#include "elements/entities/enemy.h"
#include "graphics/texture.h"
#include "scene/world_scene.h"

void enemy_vertical_pattern(enemy_t *enemy,
sfVector2f *move, infos_t *infos, float speed)
{
    UNUSED(infos);
    if (enemy->move_status == 1 &&
    ((enemy->dist > 0 && enemy->pos.y > enemy->pos_start.y + enemy->dist)
    || (enemy->dist < 0 && enemy->pos.y < enemy->pos_start.y + enemy->dist)))
        enemy->move_status = 2;
    if (enemy->move_status == 2 &&
    ((enemy->dist > 0 && enemy->pos.y < enemy->pos_start.y)
    || (enemy->dist < 0 && enemy->pos.y > enemy->pos_start.y)))
        enemy->move_status = 1;
    if (enemy->move_status == 1)
        *move = (sfVector2f) {0, enemy->dist > 0 ? speed : -speed};
    else if (enemy->move_status == 2)
        *move = (sfVector2f) {0, enemy->dist > 0 ? -speed : speed};
}

void enemy_horizonthal_pattern(enemy_t *enemy,
sfVector2f *move, infos_t *infos, float speed)
{
    UNUSED(infos);
    if (enemy->move_status == 1 &&
    ((enemy->dist > 0 && enemy->pos.x > enemy->pos_start.x + enemy->dist)
    || (enemy->dist < 0 && enemy->pos.x < enemy->pos_start.x + enemy->dist)))
        enemy->move_status = 2;
    if (enemy->move_status == 2 &&
    ((enemy->dist > 0 && enemy->pos.x < enemy->pos_start.x)
    || (enemy->dist < 0 && enemy->pos.x > enemy->pos_start.x)))
        enemy->move_status = 1;
    if (enemy->move_status == 1)
        *move = (sfVector2f) {enemy->dist > 0 ? speed : -speed, 0};
    else if (enemy->move_status == 2)
        *move = (sfVector2f) {enemy->dist > 0 ? -speed : speed, 0};
}
