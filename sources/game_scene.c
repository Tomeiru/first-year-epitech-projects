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

void rect_change(tower_t *buffer)
{
    if (buffer->texture_rect.left == 360)
        buffer->texture_rect.left = 0;
    else 
        buffer->texture_rect.left += 120;
}

void adjust_rect_tower(game_t *game)
{
    tower_t *buffer = game->game_scene->tower;
    sfTime time = sfClock_getElapsedTime(game->clock->clock);
    float time_value = sfTime_asSeconds(time);

    if (game->game_scene->time_check_rec == 0) {
        game->game_scene->rec_time = sfTime_asSeconds(time);
        game->game_scene->time_check_rec = 1;
    }
    if (time_value - game->game_scene->rec_time > 0.25) {
        while (buffer != NULL) {
            rect_change(buffer);
            buffer = buffer->next;
        }
        game->game_scene->time_check_rec = 0;
    }
}

void damage_enemy(ennemy_t *buffer, game_t *game)
{
    while (buffer != NULL) {
        buffer->HP -= game->game_scene->damage_cycle;
        if (buffer->HP <= 0)
            buffer->display = 0;
        buffer = buffer->next;
    }
}

void attack_cycle(game_t *game)
{
    ennemy_t *buffer = game->game_scene->ennemies;
    sfTime time = sfClock_getElapsedTime(game->clock->clock);
    float time_value = sfTime_asSeconds(time);

    if (game->game_scene->time_check_cycle == 0) {
        game->game_scene->elapsed_cycle = sfTime_asSeconds(time);
        game->game_scene->time_check_cycle = 1;
    }
    if (time_value - game->game_scene->elapsed_cycle > game->game_scene->
    time_cycle) {
        if (game->game_scene->wave.phase == 0)
            damage_enemy(buffer, game);
        game->game_scene->gold += game->game_scene->gold_cycle;
        game->game_scene->time_check_cycle = 0;
    }
}

void game_scene(sfRenderWindow *window, game_t *game)
{
    if (game->stats->num_scene != GAME)
        return;
    adjust_rect_map(game);
    draw_game_map(window, game);
    adjust_rect_tower(game);
    display_tower(window, game);
    wave(game, window);
    attack_cycle(game);
    draw_texts(game, window);
}
