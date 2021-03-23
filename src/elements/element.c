/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** element
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "elements/element.h"

element_t *element_create_default(size_t size,
element_type_t type, sfVector2f pos)
{
    element_t *element = malloc(size);

    if (!element)
        return (NULL);
    element->type = type;
    element->pos = pos;
    element->rot = 0;
    element->hitbox = (sfIntRect) {pos.x, pos.y, 0, 0};
    element->move = &default_element_move;
    element->rotate = &default_element_rotate;
    element->draw = &default_element_draw;
    element->on_click = NULL;
    element->set_infos = NULL;
    element->destroy = &default_element_destroy;
    return (element);
}

void element_set_hitbox(element_t *element, sfFloatRect global_bounds)
{
    element->hitbox.width = (int) global_bounds.width;
    element->hitbox.height = (int) global_bounds.height;
}

char element_point_hit(element_t *element, sfVector2f pos)
{
    sfIntRect hb = element->hitbox;

    return (pos.x >= hb.left && pos.x <= hb.left + hb.width
    && pos.y >= hb.top && pos.y <= hb.top + hb.height);
}

element_t *element_get_closest(infos_t *infos,
sfVector2f pos, element_type_t type)
{
    element_t *element;
    element_t *closest = NULL;
    float dist = 1000000;
    float elem_dist = 0;

    for (list_t *list = infos->scene->entities; list; list = list->next) {
        element = (element_t*) list->data;
        if (element->type != type)
            continue;
        elem_dist = get_distance(pos, element->pos);
        if (elem_dist < dist) {
            closest = element;
            dist = elem_dist;
        }
    }
    return (closest);
}