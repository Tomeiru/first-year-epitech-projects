/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** physics
*/

#include "my_rpg.h"
#include "map.h"

void prior_map_collision(sfVector2f *move, sfIntRect hb, map_t *map)
{
    hb.left += move->x;
    hb.top += move->y;
    if ((move->x == 0 && move->y == 0) ||
    map_check_mask(map, hb, WALL_MASK_VALUE).r == 0)
        return;
    hb.left -= move->x;
    if (map_check_mask(map, hb, WALL_MASK_VALUE).r == 0) {
        move->x = 0;
        return;
    }
    hb.left += move->x;
    hb.top -= move->y;
    if (map_check_mask(map, hb, WALL_MASK_VALUE).r == 0) {
        move->y = 0;
        return;
    }
}