/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** hud
*/

#ifndef HUD_H_
#define HUD_H_

#include "graphics/subwindow.h"
#include "elements/health_bar.h"
#include "elements/entities/particles/meteo.h"
#include "elements/entities/text.h"

typedef struct hud_s {
    sfSprite *background;
    sfVector2f pos;
    list_t *elements;
    list_t *entities;
    subwindow_move_fct_t move;
    subwindow_update_fct_t update;
    subwindow_draw_fct_t draw;
    subwindow_destroy_fct_t destroy;
    health_bar_t *health_bar;
    buffer_t *meteo;
    text_t *action_text;
} hud_t;

hud_t *hud_create(infos_t *infos);

#endif /* !HUD_H_ */
