/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** origins
*/

#include <SFML/Graphics.h>

void sprite_set_origin_center(sfSprite *sprite)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(sprite);
    sfVector2f center = {rect.width / 2, rect.height / 2};

    sfSprite_setOrigin(sprite, center);
}

void text_set_origin_center(sfText *text)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfVector2f center = {rect.width / 2, rect.height / 2};

    sfText_setOrigin(text, center);
}