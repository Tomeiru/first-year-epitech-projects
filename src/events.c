/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** events
*/

#include "my_rpg.h"
#include "actions.h"
#include "graphics/subwindow.h"
#include "elements/entities/button.h"

static int manage_mouse_button_evt(infos_t *infos,
sfMouseButtonEvent *mouse_ev)
{
    sfVector2f pos =
    sfRenderWindow_mapPixelToCoords(infos->window, (sfVector2i)
    {mouse_ev->x, mouse_ev->y}, sfRenderWindow_getView(infos->window));
    int ret;

    for (list_t *list = infos->scene->subwindows; list; list = list->next) {
        ret = on_click_interact(((subwindow_t*) list->data)->elements,
        infos, pos, mouse_ev);
        if (ret > -1)
            return (ret);
    }
    ret = on_click_interact(infos->scene->elements, infos, pos, mouse_ev);
    return (ret > -1 ? ret : 0);
}

int poll_events(infos_t *infos)
{
    sfEvent event;
    int user_tmp = 0;
    int scene_tmp = 0;
    int action = 0;

    while (sfRenderWindow_pollEvent(infos->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(infos->window);
            continue;
        } else if (event.type == sfEvtMouseButtonPressed)
            user_tmp = manage_mouse_button_evt(infos, &(event.mouseButton));
        if (infos->scene->event)
            scene_tmp = infos->scene->event(infos->scene, infos, &event);
        if (scene_tmp || user_tmp)
            action = scene_tmp ? scene_tmp : user_tmp;
    }
    return (action);
}