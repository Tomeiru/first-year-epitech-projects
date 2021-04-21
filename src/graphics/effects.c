/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** graphicals effects
*/

#include "my_rpg.h"
#include "elements/element.h"
#include "map.h"

void element_behind_wall(element_t *element, map_t *map)
{
    sfColor color_filter = {0, 0, 0, 180};

    if (map_check_mask(map, element->hitbox, BEHIND_WALL_MASK_VALUE).r)
        sfSprite_setColor(element->sprite, color_filter);
    else
        sfSprite_setColor(element->sprite, sfWhite);
}