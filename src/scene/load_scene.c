/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** load scene
*/

#include "my_rpg.h"
#include "actions.h"
#include "scene/scene_list.h"

int load_scene(infos_t *infos, int action)
{
    const sfView *view = sfRenderWindow_getView(infos->window);

    for (int i = 0; i < NB_SCENES; i++) {
        if (LOAD_ACTION[i] == action) {
            infos->state = SCENE_STATE[i];
            infos->scene = LOAD_SCENE_FCT[i](infos);
            break;
        }
    }
    if (infos->scene == NULL)
        return (1);
    if (action == LOAD_WORLD_SCENE_ACTION)
        execute_rpgsh(((world_scene_t*) infos->scene)->map->script, infos);
    sfView_setCenter(view, (sfVector2f) {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
    sfRenderWindow_setView(infos->window, view);
    return (0);
}