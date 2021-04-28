/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** animation utils
*/

#include <SFML/Graphics.h>

void living_walk_animation(sfSprite *sprite,
sfVector2f move, float *anim, float speed)
{
    int row = 0;
    int col = 0;

    if (move.y == 0) {
        if (move.x < 0)
            row = 1;
        else if (move.x > 0)
            row = 2;
    } else {
        if (move.y < 0)
            row = 3;
    }
    *anim += speed;
    if (*anim >= 120)
        *anim = 0;
    col = ((int) *anim) / 30;
    sfSprite_setTextureRect(sprite,
    (sfIntRect) {col * 64, row * 64, 64, 64});
}