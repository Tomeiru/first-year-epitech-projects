/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** cast_struct
*/

#include "../include/my_defender.h"

//CAST ?!?!

sfVector2f create_float_vector(int x, int y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfFloatRect create_float_rect(float top, float left, float width, float height)
{
    sfFloatRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfIntRect create_int_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}