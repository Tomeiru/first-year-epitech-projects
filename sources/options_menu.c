/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** options_menu
*/

#include "../include/my_defender.h"

void draw_options_buttons(game_t *game, sfRenderWindow *window)
{
    draw_sprites_wo_speed(window, game->scenes[1]->entities[11]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[0]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[1]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[2]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[3]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[4]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[5]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[6]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[7]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[8]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[9]);
    draw_sprites_wo_speed(window, game->scenes[1]->entities[10]);
}

void adjust_rect_volume_sound(entity_t **entities, options_t *options)
{
    entities[0]->texture_rect.left = options->sound_off * 300;
    entities[1]->texture_rect.left = options->volume_off * 300;
    entities[2]->texture_rect.left = options->grid_off * 300;
}

void adjust_rect_fps(entity_t **entities, options_t *options)
{
    entities[3]->texture_rect.left = 200;
    entities[4]->texture_rect.left = 200;
    entities[5]->texture_rect.left = 200;
    entities[6]->texture_rect.left = 200;
    entities[options->fps + 3]->texture_rect.left = 0;
}

void adjust_rect_resolution(entity_t **entities, options_t *options)
{
    entities[7]->texture_rect.left = 200;
    entities[8]->texture_rect.left = 200;
    entities[9]->texture_rect.left = 200;
    entities[10]->texture_rect.left = 200;
    entities[options->resolution + 7]->texture_rect.left = 0;
}

void option_menu(sfRenderWindow *window, game_t *game)
{
    if (game->stats->num_scene != OPTIONS)
        return;
    adjust_rect_volume_sound(game->scenes[1]->entities, game->options);
    adjust_rect_fps(game->scenes[1]->entities, game->options);
    adjust_rect_resolution(game->scenes[1]->entities, game->options);
    draw_options_buttons(game, window);
}