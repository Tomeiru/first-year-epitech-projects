/*
** EPITECH PROJECT, 2021
** myDefender
** File description:
** subwindow
*/

#include <stdlib.h>
#include "scene/subwindow.h"
#include "elements/entities/entity.h"

subwindow_t *subwindow_create(infos_t *infos,
sfVector2f pos, texture_t texture)
{
    subwindow_t *subwindow = malloc(sizeof(subwindow_t));
    sfSprite *sprite = sfSprite_create();

    if (!subwindow)
        return (NULL);
    sfSprite_setTexture(sprite, get_texture(infos, texture), 0);
    sfSprite_setPosition(sprite, pos);
    subwindow->background = sprite;
    subwindow->pos = pos;
    subwindow->elements = NULL;
    subwindow->entities = NULL;
    return (subwindow);
}

void subwindow_add_element(subwindow_t *subwindow,
element_t *element, char entity)
{
    create_list(&(subwindow->elements), element);
    if (entity)
        create_list(&(subwindow->entities), element);
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