/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** physics
*/

#include "my_rpg.h"
#include "map.h"

void prior_map_collision(sfVector2f *move,
sfIntRect hb, float speed, map_t *map)
{
    sfVector2f normalize = vector_normalize(*move);
    sfVector2f substract =
    {normalize.x * speed / 10, normalize.y * speed / 10};

    if (move->x == 0 && move->y == 0)
        return;
    hb.left += move->x;
    hb.top += move->y;
    for (int i = 0; i < 11; i++) {
        if (!map_collision(map, hb)) {
            move->x -= substract.x * i;
            move->y -= substract.y * i;
            return;
        }
        hb.left -= substract.x;
        hb.top -= substract.y;
    }
    move->x = 0;
    move->y = 0;
}