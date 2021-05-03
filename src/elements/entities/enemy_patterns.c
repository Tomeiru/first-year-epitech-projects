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

void enemy_vertical_move(enemy_t *enemy, sfVector2f *move, int speed)
{
    if (enemy->move_status == 1 && enemy->pos.y > enemy->pos_start.y + 200)
        enemy->move_status = 2;
    if (enemy->move_status == 2 && enemy->pos.y < enemy->pos_start.y)
        enemy->move_status = 1;
    if (enemy->move_status == 1)
        *move = (sfVector2f){0, speed};
    if (enemy->move_status == 2)
        *move = (sfVector2f){0, -speed};
}

void enemy_horizontal_move(enemy_t *enemy, sfVector2f *move, int speed)
{
    if (enemy->move_status == 1 && enemy->pos.x > enemy->pos_start.x + 200)
        enemy->move_status = 2;
    if (enemy->move_status == 2 && enemy->pos.x < enemy->pos_start.x)
        enemy->move_status = 1;
    if (enemy->move_status == 1)
        *move = (sfVector2f){speed, 0};
    if (enemy->move_status == 2)
        *move = (sfVector2f){-speed, 0};
}

void enemy_horizontal_update(entity_t *entity, infos_t *infos, float elapsed)
{
    enemy_t *enemy = (enemy_t *) entity;
    sfVector2f move;

    enemy_horizontal_move(enemy, &move, elapsed * 2);
    enemy->move((element_t *) enemy, (sfVector2f){enemy->pos.x + move.x,
        enemy->pos.y + move.y});
    UNUSED(infos);
}

void enemy_vertical_update(entity_t *entity, infos_t *infos, float elapsed)
{
    enemy_t *enemy = (enemy_t *) entity;
    sfVector2f move;

    enemy_vertical_move(enemy, &move, elapsed * 2);
    enemy->move((element_t *) enemy, (sfVector2f){enemy->pos.x + move.x,
        enemy->pos.y + move.y});
    UNUSED(infos);
}