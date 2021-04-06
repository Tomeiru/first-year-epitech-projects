/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** pause
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "graphics/pause.h"
#include "graphics/texture.h"
#include "elements/entities/button.h"

static int pause_create_buttons(pause_t *pause, infos_t *infos)
{
    button_t *resume = text_button_create(infos,
    "Reprendre", (sfVector2f) {865, 350}, GREEN_BUTTON);
    button_t *menu =
    text_button_create(infos, "Menu", (sfVector2f) {865, 500}, BLUE_BUTTON);
    button_t *leave =
    text_button_create(infos, "Quitter", (sfVector2f) {865, 650}, RED_BUTTON);

    if (!resume || !menu || !leave)
        return (1);
    resume->on_click = &button_pause_resume;
    menu->on_click = &button_load_menu_scene;
    leave->on_click = &button_close_game;
    subwindow_add_element((subwindow_t*) pause, (element_t*) resume, 1);
    subwindow_add_element((subwindow_t*) pause, (element_t*) menu, 1);
    subwindow_add_element((subwindow_t*) pause, (element_t*) leave, 1);
    return (0);
}

pause_t *pause_create(infos_t *infos)
{
    pause_t *pause = (pause_t*) subwindow_create(sizeof(pause_t),
    infos, (sfVector2f) {0, 1081}, PAUSE_BACKGROUND_TEXT);

    if (!pause || pause_create_buttons(pause, infos))
        return (NULL);
    pause->update = &pause_update;
    pause->draw = &pause_draw;
    pause->anim = 0;
    pause->pause = 0;
    return (pause);
}

void pause_update(subwindow_t *subwindow, infos_t *infos, float elapsed)
{
    pause_t *pause = (pause_t*) subwindow;
    const sfView *view = sfRenderWindow_getView(infos->window);

    if (pause->pause && pause->anim)
        pause_anim_move(pause, view, 0, elapsed);
    else if (!pause->pause && pause->anim)
        pause_anim_move(pause, view, 1081, elapsed);
}

void pause_draw(subwindow_t *subwindow, sfRenderWindow *window)
{
    pause_t *pause = (pause_t*) subwindow;

    if (!pause->pause && !pause->anim)
        return;
    subwindow_default_draw(subwindow, window);
}