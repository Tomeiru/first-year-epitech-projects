/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button load actions
*/

#include "my_rpg.h"
#include "elements/entities/button.h"
#include "actions.h"

int button_close_game(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    button_set_clicked(button, 1, infos);
    return (QUIT_GAME_ACTION);
}

int button_load_menu_scene(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    button_set_clicked(button, 1, infos);
    return (LOAD_MENU_SCENE_ACTION);
}

int button_load_settings_scene(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    button_set_clicked(button, 1, infos);
    return (LOAD_SETTINGS_SCENE_ACTION);
}

int button_load_howtoplay_scene(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    button_set_clicked(button, 1, infos);
    return (LOAD_HOWTOPLAY_SCENE_ACTION);
}

int button_load_world_scene(element_t *element,
infos_t *infos, sfMouseButton button_type)
{
    button_t *button = (button_t*) element;

    button_set_clicked(button, 1, infos);
    return (LOAD_WORLD_SCENE_ACTION);
}
