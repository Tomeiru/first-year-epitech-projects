/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** default element fct
*/

#include <stdlib.h>
#include "elements/element.h"

void default_element_move(element_t *element, sfVector2f pos)
{
    sfVector2f origin = sfSprite_getOrigin(element->sprite);

    element->pos = pos;
    element->hitbox.left = pos.x - origin.x;
    element->hitbox.top = pos.y - origin.y;
    sfSprite_setPosition(element->sprite, pos);
}

void default_element_rotate(element_t *element, float rot)
{
    element->rot = rot;
    sfSprite_setRotation(element->sprite, rot);
}

void default_element_draw(element_t *element, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, element->sprite, NULL);
}

void default_element_destroy(element_t *element)
{
    sfSprite_destroy(element->sprite);
    free(element);
}