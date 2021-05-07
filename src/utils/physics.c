/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** physics
*/

#include "my_rpg.h"
#include "map.h"

void prior_map_collision(sfVector2f *move, sfIntRect hb, map_t *map)
{
    hb.left += move->x;
    hb.top += move->y;
    if ((move->x == 0 && move->y == 0) ||
    map_check_mask(map, hb, WALL_MASK_VALUE).r == 0)
        return;
    hb.left -= move->x;
    if (map_check_mask(map, hb, WALL_MASK_VALUE).r == 0) {
        move->x = 0;
        return;
    }
    hb.left += move->x;
    hb.top -= move->y;
    if (map_check_mask(map, hb, WALL_MASK_VALUE).r == 0) {
        move->y = 0;
        return;
    }
    move->x = 0;
    move->y = 0;
}

void player_prior_element_collision(element_t *element,
sfVector2f *move, sfIntRect hb, infos_t *infos)
{
    hb.left += move->x;
    hb.top += move->y;
    if ((move->x == 0 && move->y == 0) ||
    !element_collision(element, hb, infos->scene->elements))
        return;
    hb.left -= move->x;
    if (!element_collision(element, hb, infos->scene->elements)) {
        move->x = 0;
        return;
    }
    hb.left += move->x;
    hb.top -= move->y;
    if (!element_collision(element, hb, infos->scene->elements)) {
        move->y = 0;
        return;
    }
    move->x = 0;
    move->y = 0;
}

void prior_element_collision(element_t *element,
sfVector2f *move, sfIntRect hb, infos_t *infos)
{
    hb.left += move->x;
    hb.top += move->y;
    if ((move->x == 0 && move->y == 0) ||
    !element_collision(element, hb, infos->scene->elements))
        return;
    move->x = 0;
    move->y = 0;
}

element_t *element_collision(element_t *element,
sfIntRect hb, list_t *elements)
{
    element_t *elem;
    sfIntRect elem_hb;

    for (list_t *list = elements; list; list = list->next) {
        elem = (element_t*) list->data;
        if (!elem || elem == element)
            continue;
        elem_hb = elem->hitbox;
        if ((elem_hb.left > hb.left + hb.width)
        || (elem_hb.left + elem_hb.width < hb.left)
        || (elem_hb.top > hb.top + hb.height)
        || (elem_hb.top + elem_hb.height < hb.top))
            continue;
        return (elem);
    }
    return (NULL);
}

void get_knockback_move(sfVector2f *move, direction_t dir, float speed)
{
    switch (dir) {
        case NORTH:
            *move = (sfVector2f) {0, speed};
            break;
        case SOUTH:
            *move = (sfVector2f) {0, -speed};
            break;
        case EAST:
            *move = (sfVector2f) {speed, 0};
            break;
        case WEST:
            *move = (sfVector2f) {-speed, 0};
            break;
    }
}