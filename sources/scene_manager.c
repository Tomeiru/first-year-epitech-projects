/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** scene_manager
*/

#include "../include/my_defender.h"

void scene_manager(sfRenderWindow *window, game_t *game)
{
    main_menu(window, game);
    option_menu(window, game);
    game_scene(window, game);
}