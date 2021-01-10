/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** game
*/

#include "my_runner.h"

void ini_rect(struct game_struct *game_man)
{
    game_man->game_gui->grass_rect.top = 0;
    game_man->game_gui->grass_rect.left = 0;
    game_man->game_gui->grass_rect.width = 2160;
    game_man->game_gui->grass_rect.height = 72;
    game_man->game_gui->ground_rect.top = 72;
    game_man->game_gui->ground_rect.left = 0;
    game_man->game_gui->ground_rect.width = 2160;
    game_man->game_gui->ground_rect.height = 72;
    game_man->game_gui->underground_rect.top = 72;
    game_man->game_gui->underground_rect.left = 0;
    game_man->game_gui->underground_rect.width = 2160;
    game_man->game_gui->underground_rect.height = 72;
    game_man->game_gui->lives_rect.top = 0;
    game_man->game_gui->lives_rect.left = 0;
    game_man->game_gui->lives_rect.width = 486;
    game_man->game_gui->lives_rect.height = 137;
}

int game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    char *name = "Runner!";
    sfRenderWindow* window;
    window = sfRenderWindow_create(mode, name, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    run_game(window);
    return (0);
}