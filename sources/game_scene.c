/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-mathieu.brujan
** File description:
** game_scene
*/

#include "../include/my_defender.h"

void draw_game_map(sfRenderWindow *window, game_t *game)
{
    draw_sprites_wo_speed(window, game->game_scene->entities[0]);
    if (game->options->grid_off == 0)
        draw_sprites_wo_speed(window, game->game_scene->entities[1]);
    draw_sprites_wo_speed(window, game->game_scene->entities[2]);
    draw_sprites_wo_speed(window, game->game_scene->entities[4]);
    draw_sprites_wo_speed(window, game->game_scene->entities[5]);
    draw_sprites_wo_speed(window, game->game_scene->entities[6]);
    draw_sprites_wo_speed(window, game->game_scene->entities[7]);
    draw_sprites_wo_speed(window, game->game_scene->entities[8]);
    draw_sprites_wo_speed(window, game->game_scene->entities[3]);
}

void game_scene(sfRenderWindow *window, game_t *game)
{
    if (game->stats->num_scene != GAME)
        return;
    draw_game_map(window, game);
    wave(game, window);
}
