/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** textbox.c
*/

#include "graphics/textbox.h"

void textbox_destroy(textbox_t *textbox)
{
    element_t *element;
    list_t *next;

    sfSprite_destroy(textbox->background);
    for (list_t *list = textbox->elements; list; list = next) {
        next = list->next;
        element = (element_t*) list->data;
        element->destroy(element);
        free(list);
    }
    free(textbox);
}

void textbox_draw(textbox_t *textbox, sfRenderWindow *window)
{
    element_t *element;

    sfRenderWindow_drawSprite(window, textbox->background, NULL);
    for (list_t *list = textbox->elements; list; list = list->next) {
        element = (element_t*) list->data;
        element->draw(element, window);
    }
}

void textbox_move(textbox_t *textbox, sfVector2f new_pos)
{
    sfVector2f diff = {new_pos.x - textbox->pos.x,
    new_pos.y - textbox->pos.y};
    sfVector2f element_pos;
    element_t *element;

    textbox->pos = new_pos;
    sfSprite_setPosition(textbox->background, new_pos);
    for (list_t *list = textbox->elements; list; list = list->next) {
        element = (element_t*) list->data;
        element_pos = (sfVector2f)
        {element->pos.x + diff.x, element->pos.y + diff.y};
        element->move(element, element_pos);
    }
}

textbox_t *textbox_create(size_t size, infos_t *infos, sfVector2f pos,
texture_t texture)
{
    textbox_t *textbox = malloc(size);
    sfSprite *sprite = sfSprite_create();

    if (!textbox)
        return (NULL);
    sfSprite_setTexture(sprite, get_texture(infos, texture), 0);
    sfSprite_setPosition(sprite, pos);
    textbox->background = sprite;
    textbox->pos = pos;
    textbox->elements = NULL;
    textbox->entities = NULL;
    textbox->move = &textbox_move;
    textbox->draw = &textbox_draw;
    textbox->write = &textbox_write;
    textbox->destroy = &textbox_destroy;
    return (textbox);
}