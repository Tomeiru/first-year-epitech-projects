/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** subwindow fcts
*/

#include <stdlib.h>
#include "graphics/subwindow.h"
#include "elements/entities/entity.h"

void subwindow_move(subwindow_t *subwindow, sfVector2f new_pos)
{
    sfVector2f diff = {new_pos.x - subwindow->pos.x,
    new_pos.y - subwindow->pos.y};
    sfVector2f element_pos;
    element_t *element;

    subwindow->pos = new_pos;
    sfSprite_setPosition(subwindow->background, new_pos);
    for (list_t *list = subwindow->elements; list; list = list->next) {
        element = (element_t*) list->data;
        element_pos = (sfVector2f)
        {element->pos.x + diff.x, element->pos.y + diff.y};
        element->move(element, element_pos);
    }
}

void subwindow_update(subwindow_t *subwindow, infos_t *infos, float elapsed)
{
    entity_t *entity;

    for (list_t *list = subwindow->entities; list; list = list->next) {
        entity = (entity_t*) list->data;
        entity->update(entity, infos, elapsed);
    }
}

void subwindow_draw(subwindow_t *subwindow, sfRenderWindow *window)
{
    element_t *element;

    sfRenderWindow_drawSprite(window, subwindow->background, NULL);
    for (list_t *list = subwindow->elements; list; list = list->next) {
        element = (element_t*) list->data;
        element->draw(element, window);
    }
}

void subwindow_destroy(subwindow_t *subwindow)
{
    element_t *element;
    list_t *next;

    sfSprite_destroy(subwindow->background);
    for (list_t *list = subwindow->elements; list; list = next) {
        next = list->next;
        element = (element_t*) list->data;
        element->destroy(element);
        free(list);
    }
    free(subwindow);
}