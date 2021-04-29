/*
** EPITECH PROJECT, 2021
** myDefender
** File description:
** subwindow
*/

#include <stdlib.h>
#include "graphics/subwindow.h"

subwindow_t *subwindow_create(size_t size, infos_t *infos,
sfVector2f pos, texture_t texture)
{
    subwindow_t *subwindow = malloc(size);
    sfSprite *sprite = texture != NULL_TEXT ? sfSprite_create() : NULL;

    if (!subwindow || (texture != NULL_TEXT && !sprite))
        return (NULL);
    if (sprite) {
        sfSprite_setTexture(sprite, get_texture(infos, texture), 0);
        sfSprite_setPosition(sprite, pos);
    }
    subwindow->background = sprite;
    subwindow->pos = pos;
    subwindow->elements = NULL;
    subwindow->entities = NULL;
    subwindow->move = &subwindow_default_move;
    subwindow->update = &subwindow_default_update;
    subwindow->draw = &subwindow_default_draw;
    subwindow->destroy = &subwindow_default_destroy;
    return (subwindow);
}

void subwindow_add_element(subwindow_t *subwindow,
element_t *element, char entity)
{
    sfVector2f new_pos = {subwindow->pos.x + element->pos.x,
    subwindow->pos.y + element->pos.y};

    element->move(element, new_pos);
    create_list(&(subwindow->elements), element);
    if (entity)
        create_list(&(subwindow->entities), element);
}