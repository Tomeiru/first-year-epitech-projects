/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** scene_manager
*/

#include "../include/my_defender.h"

void tutorial(sfRenderWindow *window, game_t *game)
{
    if (game->stats->num_scene != TUTO)
        return;
    sfRenderWindow_drawSprite(window,game->stats->tuto, NULL);
}

void scene_manager(sfRenderWindow *window, game_t *game)
{
    main_menu(window, game);
    option_menu(window, game);
    game_scene(window, game);
    tutorial(window, game);
}