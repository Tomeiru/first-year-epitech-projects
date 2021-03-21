/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** events_options_menu
*/

#include "../include/my_defender.h"

void turn_sound_on_or_off(options_t *options, game_t *game)
{
    if (options->sound_off == 0)
        options->sound_off = 1;
    else {
        options->sound_off = 0;
        sfSound_setVolume(game->scenes[0]->sound[2], (float)100);
        sfSound_play(game->scenes[0]->sound[2]);
    }
}

void turn_volume_on_or_off(options_t *options)
{
    if (options->volume_off == 0)
        options->volume_off = 1;
    else
        options->volume_off = 0;
}

void turn_grid_on_or_off(options_t *options)
{
    if (options->grid_off == 0)
        options->grid_off = 1;
    else
        options->grid_off = 0;
}

void cursor_on_volume_sound(entity_t **entities, mouse_t *mouse_info,
    game_t *game)
{
    if (!(mouse_info->rpos.x >= entities[0]->position.x && mouse_info->rpos.x <=
        entities[0]->position.x + entities[0]->texture_rect.width))
        return;
    if (mouse_info->rpos.y >= entities[0]->position.y && mouse_info->rpos.y <=
        entities[0]->position.y + entities[0]->texture_rect.height) {
        turn_sound_on_or_off(game->options, game);
    }
    if (mouse_info->rpos.y >= entities[1]->position.y && mouse_info->rpos.y <=
        entities[1]->position.y + entities[1]->texture_rect.height) {
        sfSound_play(game->scenes[0]->sound[2]);
        turn_volume_on_or_off(game->options);
    }
    if (mouse_info->rpos.y >= entities[2]->position.y && mouse_info->rpos.y <=
        entities[2]->position.y + entities[2]->texture_rect.height) {
        sfSound_play(game->scenes[0]->sound[2]);
        turn_grid_on_or_off(game->options);
    }
}

void left_click_options_event(game_t *game, sfRenderWindow *window)
{
    cursor_on_volume_sound(game->scenes[1]->entities, game->mouse_info,
    game);
    cursor_on_fps(game->scenes[1]->entities, game->mouse_info,
    game, window);
    cursor_on_resolution(game->scenes[1]->entities, game->mouse_info,
    game, window);
}