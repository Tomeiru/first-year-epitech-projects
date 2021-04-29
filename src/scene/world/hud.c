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
    health_bar_t *health_bar =
    health_bar_create(infos, (sfVector2f) {15, 15}, 6, 6);
    buffer_t *meteo = meteo_create();
    text_t *action_text = text_create("", infos->font,
    (sfVector2f) {10, 1000}, 60);

    if (!hud || !health_bar || !meteo || !action_text)
        return (NULL);
    hud->health_bar = health_bar;
    hud->meteo = meteo;
    hud->action_text = action_text;
    subwindow_add_element((subwindow_t*) hud, (element_t*) health_bar, 0);
    subwindow_add_element((subwindow_t*) hud, (element_t*) meteo, 1);
    subwindow_add_element((subwindow_t*) hud, (element_t*) action_text, 0);
    return (hud);
}