/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** events_options_menu
*/

#include "../include/my_defender.h"

void cursor_on_volume_sound(entity_t **entities, mouse_t *mouse_info,
options_t *options)
{
    if (!(mouse_info->pos.y >= entities[0]->position.y && mouse_info->pos.y <= 
    entities[0]->position.y + entities[0]->texture_rect.height))
        return;
    if (mouse_info->pos.x >= entities[0]->position.x && mouse_info->pos.x <= 
    entities[0]->position.x + entities[0]->texture_rect.width) {
        if (options->sound_off == 0)
            options->sound_off = 1;
        else
            options->sound_off = 0;
    } if (mouse_info->pos.x >= entities[1]->position.x && mouse_info->pos.x <= 
    entities[1]->position.x + entities[1]->texture_rect.width) {
        if (options->volume_off == 0)
            options->volume_off = 1;
        else
            options->volume_off = 0;
    }
}

void cursor_on_fps(entity_t **entities, mouse_t *mouse_info,
options_t *options, sfRenderWindow *window)
{
    if (!(mouse_info->pos.y >= entities[4]->position.y && mouse_info->pos.y <= 
    entities[4]->position.y + entities[4]->texture_rect.height))
        return;
    if (mouse_info->pos.x >= entities[4]->position.x && mouse_info->pos.x <= 
    entities[4]->position.x + entities[4]->texture_rect.width) {
        options->fps = 0;
        sfRenderWindow_setFramerateLimit(window, 10);
    } if (mouse_info->pos.x >= entities[5]->position.x && mouse_info->pos.x <= 
    entities[5]->position.x + entities[5]->texture_rect.width) {
        options->fps = 1;
        sfRenderWindow_setFramerateLimit(window, 30);
    } if (mouse_info->pos.x >= entities[6]->position.x && mouse_info->pos.x <= 
    entities[6]->position.x + entities[6]->texture_rect.width) {
        options->fps = 2;
        sfRenderWindow_setFramerateLimit(window, 60);
    } if (mouse_info->pos.x >= entities[7]->position.x && mouse_info->pos.x <= 
    entities[7]->position.x + entities[7]->texture_rect.width) {
        options->fps = 3;
        sfRenderWindow_setFramerateLimit(window, 120);
    }
}

void change_resolution(sfRenderWindow *window, int x)
{
    sfView *view;

    if (x == 0)
        view = create_view(480, 270);
    if (x == 1)
        view = create_view(960, 540);
    if (x == 2)
        view = create_view(1440, 810);
    if (x == 3)
        view = create_view(1920, 1080);
    sfRenderWindow_setView(window, view);
}

void cursor_on_resolution(entity_t **entities, mouse_t *mouse_info,
options_t *options, sfRenderWindow *window)
{
    if (!(mouse_info->pos.y >= entities[8]->position.y && mouse_info->pos.y <= 
    entities[8]->position.y + entities[8]->texture_rect.height))
        return;
    if (mouse_info->pos.x >= entities[8]->position.x && mouse_info->pos.x <= 
    entities[8]->position.x + entities[8]->texture_rect.width) {
        options->resolution = 0;
        change_resolution(window, 0);
    } if (mouse_info->pos.x >= entities[9]->position.x && mouse_info->pos.x <= 
    entities[9]->position.x + entities[9]->texture_rect.width) {
        options->resolution = 1;
        change_resolution(window, 1);
    } if (mouse_info->pos.x >= entities[10]->position.x && mouse_info->pos.x <= 
    entities[10]->position.x + entities[10]->texture_rect.width) {
        options->resolution = 2;
        change_resolution(window, 2);
    } if (mouse_info->pos.x >= entities[11]->position.x && mouse_info->pos.x <= 
    entities[11]->position.x + entities[11]->texture_rect.width) {
        options->resolution = 3;
        change_resolution(window, 3);
    }
}

void left_click_options_event(game_t *game, sfRenderWindow *window)
{
    cursor_on_volume_sound(game->scenes[1]->entities, game->mouse_info,
    game->options);
    cursor_on_fps(game->scenes[1]->entities, game->mouse_info,
    game->options, window);
    cursor_on_resolution(game->scenes[1]->entities, game->mouse_info,
    game->options, window);
}