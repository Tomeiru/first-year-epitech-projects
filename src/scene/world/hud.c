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

static int hud_setup(infos_t *infos, hud_t *hud)
{
    health_bar_t *health_bar =
    health_bar_create(infos, (sfVector2f) {15, 15}, 6, 6);
    bar_t *stamina_bar = bar_create(infos,
    (sfIntRect) {30, 100, 300, 40}, 100);

    if (!health_bar || !stamina_bar)
        return (1);
    hud->health_bar = health_bar;
    hud->stamina_bar = stamina_bar;
    subwindow_add_element((subwindow_t*) hud, (element_t*) health_bar, 0);
    subwindow_add_element((subwindow_t*) hud, (element_t*) stamina_bar, 0);
    return (0);
}

hud_t *hud_create(infos_t *infos)
{
    hud_t *hud = (hud_t*) subwindow_create(sizeof(hud_t),
    infos, (sfVector2f) {0, 0}, -1);
    buffer_t *meteo = meteo_create();
    dialogue_t *dialogue = dialogue_create(infos, (sfVector2f) {360, 880});
    text_t *action_text = text_create("", infos->font,
    (sfVector2f) {10, 1000}, 60);

    if (!hud || !meteo || !dialogue || !action_text || hud_setup(infos, hud))
        return (NULL);
    hud->meteo = meteo;
    hud->dialogue = dialogue;
    hud->action_text = action_text;
    subwindow_add_element((subwindow_t*) hud, (element_t*) meteo, 1);
    subwindow_add_element((subwindow_t*) hud, (element_t*) dialogue, 1);
    subwindow_add_element((subwindow_t*) hud, (element_t*) action_text, 0);
    return (hud);
}