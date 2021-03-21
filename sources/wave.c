/*
** EPITECH PROJECT, 2021
** mydefender
** File description:
** wave
*/

#include "../include/my_defender.h"

void init_wave(game_t *game)
{
    game->game_scene->castle_pv = 1000000;
    game->clock->wave_time = sfClock_getElapsedTime(game->clock->clock).microseconds / 1000000;
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
    return;
}//OK

void wave(game_t *game, sfRenderWindow *window)
{
    if (game->game_scene->wave.phase == 0) {
        if (sfClock_getElapsedTime(game->clock->clock).microseconds
        / 1000000 - game->clock->wave_time > 15)
            game->game_scene->wave.phase = 1;
    } else {
        gestion_mobs(game, window);
        if (game->game_scene->wave.nbr_ennemies == 0)
            end_wave(game);
    }
    return;
}//OK run in loop