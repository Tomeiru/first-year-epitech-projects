/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** options_menu
*/

#include "../include/my_defender.h"

void draw_options_buttons(game_t *game, sfRenderWindow *window)
{
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
    draw_sprites_wo_speed(window, game->scenes[1]->entities[11]);
}

void adjust_rect_volume_sound(entity_t **entities, options_t *options)
{
    entities[0]->texture_rect.left = options->sound_off * 200;
    entities[1]->texture_rect.left = options->volume_off * 200;
}

void adjust_rect_fps(entity_t **entities, options_t *options)
{
    entities[4]->texture_rect.left = 100;
    entities[5]->texture_rect.left = 100;
    entities[6]->texture_rect.left = 100;
    entities[7]->texture_rect.left = 100;
    entities[options->fps + 4]->texture_rect.left = 0;
}

void adjust_rect_resolution(entity_t **entities, options_t *options)
{
    entities[8]->texture_rect.left = 100;
    entities[9]->texture_rect.left = 100;
    entities[10]->texture_rect.left = 100;
    entities[11]->texture_rect.left = 100;
    entities[options->resolution + 8]->texture_rect.left = 0;
}

void adjust_rect_options(entity_t **entities, options_t *options)
{
    adjust_rect_volume_sound(entities, options);
    adjust_rect_fps(entities, options);
    adjust_rect_resolution(entities, options);
}

void option_menu(sfRenderWindow *window, game_t *game)
{
    if (game->stats->num_scene != OPTIONS)
        return;
    adjust_rect_options(game->scenes[1]->entities, game->options);
    draw_options_buttons(game, window);
}