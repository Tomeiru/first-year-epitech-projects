/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** bar
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "elements/bar.h"
#include "graphics/texture.h"

static int bar_setup(bar_t *bar, infos_t *infos,
sfVector2f pos, sfVector2f size)
{
    sfRectangleShape *bkgd_rect = sfRectangleShape_create();
    sfRectangleShape *bar_rect = sfRectangleShape_create();
    sfTexture *texture = get_texture(infos, BARS_TEXT);

    if (!bkgd_rect || !bar_rect)
        return (1);
    sfRectangleShape_setPosition(bkgd_rect, pos);
    sfRectangleShape_setSize(bkgd_rect, size);
    sfRectangleShape_setTexture(bkgd_rect, texture, 0);
    sfRectangleShape_setTextureRect(bkgd_rect, (sfIntRect) {0, 0, 200, 50});
    sfRectangleShape_setPosition(bar_rect, pos);
    sfRectangleShape_setSize(bar_rect, size);
    sfRectangleShape_setTexture(bar_rect, texture, 0);
    sfRectangleShape_setTextureRect(bar_rect, (sfIntRect) {0, 50, 200, 50});
    bar->bkgd = bkgd_rect;
    bar->bar = bar_rect;
    return (0);
}

bar_t *bar_create(infos_t *infos, sfIntRect rect, float max_value)
{
    sfVector2f pos = {rect.left, rect.top};
    sfVector2f size = {rect.width, rect.height};
    bar_t *bar = (bar_t*) element_create_default(sizeof(bar_t), BAR, pos);

    if (!bar || bar_setup(bar, infos, pos, size))
        return (NULL);
    bar->move = &bar_move;
    bar->draw = &bar_draw;
    bar->destroy = &bar_destroy;
    bar->size = size;
    bar->value = max_value;
    bar->max = max_value;
    bar->color_id = 0;
    return (bar);
}

void bar_set_value(bar_t *bar, float value)
{
    float factor = value / bar->max;
    sfVector2f size = {bar->size.x * factor, bar->size.y};
    sfIntRect rect = {0, 50 + bar->color_id * 50, factor * 200, 50};

    sfRectangleShape_setSize(bar->bar, size);
    sfRectangleShape_setTextureRect(bar->bar, rect);
    bar->value = value;
}

void bar_set_color(bar_t *bar, unsigned int color_id)
{
    if (color_id >= 2)
        color_id = 0;
    bar->color_id = color_id;
}