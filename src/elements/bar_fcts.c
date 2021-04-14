/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** bar
*/

#include <stdlib.h>
#include "elements/bar.h"

void bar_move(element_t *element, sfVector2f pos)
{
    bar_t *bar = (bar_t*) element;

    bar->pos = pos;
    sfRectangleShape_setPosition(bar->bkgd, pos);
    sfRectangleShape_setPosition(bar->bar, pos);
}

void bar_draw(element_t *element, sfRenderWindow *window)
{
    bar_t *bar = (bar_t*) element;

    sfRenderWindow_drawRectangleShape(window, bar->bkgd, NULL);
    sfRenderWindow_drawRectangleShape(window, bar->bar, NULL);
}

void bar_destroy(element_t *element)
{
    bar_t *bar = (bar_t*) element;

    sfRectangleShape_destroy(bar->bkgd);
    sfRectangleShape_destroy(bar->bar);
    free(bar);
}