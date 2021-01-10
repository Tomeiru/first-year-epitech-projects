/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** ini_struct
*/

#include "my_runner.h"

struct stats *ini_stats_struct(void)
{
    struct stats *game_stats = malloc(sizeof(struct stats));

    game_stats->score = 0;
    game_stats->high_score = 0;
    game_stats->lives = 3;
    game_stats->phase = 0;
    game_stats->moving_ground = 0;
    game_stats->is_jumping = 0;
    game_stats->clock_restart = 0;
    game_stats->animation = 0;
    game_stats->animation_run = 0;
    game_stats->need_spawn = 1;
    game_stats->invicible = 0;
    game_stats->dodge = 0;
    game_stats->speed = 10;
    game_stats->ouch = 0;
    return (game_stats);
}

struct gui *ini_gui_struct(void)
{
    struct gui *game_gui = malloc(sizeof(struct gui));

    game_gui->bg_rect.top = 0;
    game_gui->bg_rect.left = 0;
    game_gui->bg_rect.width = 1920;
    game_gui->bg_rect.height = 1080;
    game_gui->jumping_mario_rect.top = 0;
    game_gui->jumping_mario_rect.left = 0;
    game_gui->jumping_mario_rect.width = 88;
    game_gui->jumping_mario_rect.height = 144;
    game_gui->mario_rect.top = 0;
    game_gui->mario_rect.left = 0;
    game_gui->mario_rect.width = 122;
    game_gui->mario_rect.height = 144;
    game_gui->obstacle_rect.top = 0;
    game_gui->obstacle_rect.left = 0;
    game_gui->obstacle_rect.width = 48;
    game_gui->obstacle_rect.height = 48;
    return (game_gui);
}

struct audio *ini_audio_struct(void)
{
    struct audio *game_audio = malloc(sizeof(struct audio));
    
    game_audio->theme_song_launched = 0;
    return (game_audio);
}

struct clock *ini_clock_struct(void)
{
    struct clock *game_clock = malloc(sizeof(struct clock));

    game_clock->immune = sfClock_create();
    game_clock->clock_restarted = 0;
    return (game_clock);
}

struct game_struct *ini_game_struct(void)
{
    struct game_struct *game_man = malloc(sizeof(struct game_struct));

    game_man->game_stats = ini_stats_struct();
    game_man->game_gui = ini_gui_struct();
    game_man->game_audio = ini_audio_struct();
    game_man->game_clock = ini_clock_struct();
    ini_rect(game_man);
    return (game_man);
}