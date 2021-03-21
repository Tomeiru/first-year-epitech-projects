/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** game_scene_second
*/

#include "../include/my_defender.h"

void check_castle(game_t *game, sfRenderWindow *window)
{
    if (game->game_scene->castle_pv > 0)
        return;
    end_wave(game);
    init_wave(game);
    sfRenderWindow_drawSprite(window,game->stats->game_over, NULL);
    sfRenderWindow_display(window);
    while (sfClock_getElapsedTime(game->clock->clock).microseconds / 1000000 -
        game->clock->wave_time < 10);
    game->stats->num_scene = MAIN_MENU;
}

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

void display_tower(sfRenderWindow *window, game_t *game)
{
    tower_t *buffer = game->game_scene->tower;

    while (buffer != NULL) {
        sfSprite_setPosition(buffer->sprite, buffer->position);
        sfSprite_setTextureRect(buffer->sprite, buffer->texture_rect);
        sfRenderWindow_drawSprite(window, buffer->sprite, NULL);
        buffer = buffer->next;
    }
}