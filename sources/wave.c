/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** wave
*/

#include "../include/my_defender.h"

void init_wave(game_t *game)
{
    game->game_scene->castle_pv = 100;
    game->clock->wave_time =
        sfClock_getElapsedTime(game->clock->clock).microseconds / 1000000;
    game->game_scene->wave.phase = 0;
    game->game_scene->wave.mobs_spawned = 0;
    game->game_scene->wave.mul_speed = 1;
    game->game_scene->wave.mul_HP = 1;
    game->game_scene->wave.mul_gold = 1;
    game->game_scene->wave.mul_damage = 1;
    game->game_scene->wave.nbr_ennemies = 0;
    game->game_scene->wave.freq_spawn = 1;
    game->game_scene->wave.index = 1;
    game->game_scene->wave.type = 1;
    game->game_scene->ennemies = NULL;
}

void free_ennemies(game_t *game)
{
    ennemy_t *next;

    for (ennemy_t *temp = game->game_scene->ennemies;
        temp->next != NULL; temp = next) {
        next = temp->next;
        free(temp);
    }
    free(next);
    return (0);
}

void end_wave(game_t *game)
{
    game->game_scene->gold += 5 * game->game_scene->wave.mul_gold;
    game->clock->wave_time = 0;
    if (game->game_scene->wave.type == 1)
        game->game_scene->wave.mul_speed += 0.1;
    if (game->game_scene->wave.type == 2)
        game->game_scene->wave.mul_HP += 0.1;
    if (game->game_scene->wave.type == 3)
        game->game_scene->wave.mul_damage += 0.1;
    if (game->game_scene->wave.type == 4)
        game->game_scene->wave.freq_spawn += 0.1;
    game->game_scene->wave.mul_gold += 0.1;
    game->game_scene->wave.mobs_spawned = 0;
    game->game_scene->wave.index += 1;
    game->game_scene->wave.nbr_ennemies = 0;
    game->game_scene->wave.type += 1;
    game->game_scene->wave.phase = 0;
    if (game->game_scene->wave.type > 4)
        game->game_scene->wave.type = 1;
    game->game_scene->ennemies = NULL;
}

void gestion_mobs(game_t *game, sfRenderWindow *window)
{
    ennemy_t *temp;

    if (sfClock_getElapsedTime(game->clock->clock).microseconds / 1000000 -
        game->clock->wave_time > 1 / game->game_scene->wave.freq_spawn &&
        game->game_scene->wave.mobs_spawned < 10 + game->game_scene->wave.index
        / 2) {
        create_mob(game);
        game->clock->wave_time =
            sfClock_getElapsedTime(game->clock->clock).microseconds / 1000000;
    }
    for (temp = game->game_scene->ennemies; temp != NULL;
        temp = temp->next) {
        if (temp->entity.position.x <= 150)
            mob_attack(game, temp);
        else
            move_mob(game, temp);
        draw_mob(window, temp);
    }
    return;
}

void wave(game_t *game, sfRenderWindow *window)
{
    if (game->game_scene->wave.phase == 0) {
        if (sfClock_getElapsedTime(game->clock->clock).microseconds
        / 1000000 - game->clock->wave_time > 15)
            game->game_scene->wave.phase = 1;
    } else {
        gestion_mobs(game, window);
        if (game->game_scene->wave.nbr_ennemies == 0) {
            end_wave(game);
            game->clock->wave_time =
                sfClock_getElapsedTime(game->clock->clock).microseconds
                / 1000000;
        }
    }
    return;
}