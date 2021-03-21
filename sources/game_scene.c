/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-mathieu.brujan
** File description:
** game_scene
*/

#include "../include/my_defender.h"

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
        if (game->game_scene->wave.phase == 1)
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
    check_castle(game, window);
}
