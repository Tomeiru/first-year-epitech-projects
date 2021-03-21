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

void adjust_rect_map(game_t *game)
{
    game->game_scene->entities[4]->texture_rect.left = 0;
    game->game_scene->entities[5]->texture_rect.left = 0;
    game->game_scene->entities[6]->texture_rect.left = 0;
    game->game_scene->entities[7]->texture_rect.left = 0;
    game->game_scene->entities[8]->texture_rect.left = 0;
    if (game->game_scene->phase == 1)
        game->game_scene->entities[4]->texture_rect.left = 150;
    if (game->game_scene->phase == 2)
        game->game_scene->entities[5]->texture_rect.left = 150;
    if (game->game_scene->phase == 3)
        game->game_scene->entities[6]->texture_rect.left = 150;
    if (game->game_scene->phase == 4)
        game->game_scene->entities[7]->texture_rect.left = 150;
    if (game->game_scene->phase == 5)
        game->game_scene->entities[8]->texture_rect.left = 150;
}

void game_scene(sfRenderWindow *window, game_t *game)
{
    if (game->stats->num_scene != GAME)
        return;
    adjust_rect_map(game);
    draw_game_map(window, game);
    wave(game, window);
}
