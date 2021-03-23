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
    for (int i = 0; i < NB_SCENES; i++) {
        if (LOAD_ACTION[i] == action) {
            infos->state = SCENE_STATE[i];
            infos->scene = LOAD_SCENE_FCT[i](infos);
            break;
        }
    }
    if (infos->scene == NULL)
        return (1);
    return (0);
}