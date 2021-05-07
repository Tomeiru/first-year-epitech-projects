/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** enemy types
*/

#include "my_rpg.h"
#include "graphics/texture.h"
#include "elements/entities/enemy.h"

enemy_t *octorok_create(sfVector2f pos,
char vertical, int dist, infos_t *infos)
{
    enemy_t *enemy = enemy_create(sizeof(enemy_t), infos, pos, OCTOROK_TEXT);

    if (!enemy)
        return (NULL);
    enemy->health = 1;
    enemy->speed = 1;
    enemy->attack = enemy_ranged_attack;
    enemy->pattern = vertical ?
    &enemy_vertical_pattern : enemy_horizonthal_pattern;
    enemy->dist = dist;
    return (enemy);
}

enemy_t *leever_create(sfVector2f pos,
char vertical, int dist, infos_t *infos)
{
    enemy_t *enemy = enemy_create(sizeof(enemy_t), infos, pos, LEEVER_TEXT);

    if (!enemy)
        return (NULL);
    enemy->health = 2;
    enemy->speed = 2;
    enemy->attack = enemy_close_attack;
    enemy->pattern = vertical ?
    &enemy_vertical_pattern : enemy_horizonthal_pattern;
    enemy->dist = dist;
    return (enemy);
}