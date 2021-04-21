/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** maths utils
*/

#include <math.h>
#include <SFML/System/Vector2.h>

sfVector2f vector_normalize(sfVector2f vec)
{
    float length = sqrt((vec.x * vec.x) + (vec.y * vec.y));

    if (length != 0)
        return ((sfVector2f) {vec.x / length, vec.y / length});
    else
        return (vec);
}