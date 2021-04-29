/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** animation utils
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"

void walk_animation_set_anim_and_dir(float *anim,
direction_t *direction, sfVector2f move, float speed)
{
    if (move.x == 0 && move.y == 0) {
        *anim = 0;
    } else {
        if (move.y == 0) {
            if (move.x < 0)
                *direction = EAST;
            else
                *direction = WEST;
        } else {
            if (move.y < 0)
                *direction = NORTH;
            else
                *direction = SOUTH;
        }
        *anim += speed;
        if (*anim >= 120)
            *anim = 0;
    }
}

void living_walk_sprite_anim(sfSprite *sprite,
direction_t direction, float anim)
{
    int row = 0;
    int col = ((int) anim) / 30;

    switch (direction) {
        case NORTH:
            row = 3;
            break;
        case SOUTH:
            row = 0;
            break;
        case EAST:
            row = 1;
            break;
        case WEST:
            row = 2;
            break;
    }
    sfSprite_setTextureRect(sprite,
    (sfIntRect) {col * 64, row * 64, 64, 64});
}