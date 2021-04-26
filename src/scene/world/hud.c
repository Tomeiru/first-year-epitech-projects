/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** player hud
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "hud.h"
#include "scene/world_scene.h"

hud_t *hud_create(infos_t *infos)
{
    hud_t *hud = (hud_t*) subwindow_create(sizeof(hud_t),
    infos, (sfVector2f) {0, 0}, -1);
    bar_t *health_bar = bar_create(infos, (sfIntRect) {15, 15, 200, 50}, 100);

    if (!hud || !health_bar)
        return (NULL);
    hud->health_bar = health_bar;
    subwindow_add_element((subwindow_t*) hud, (element_t*) health_bar, 0);
    return (hud);
}