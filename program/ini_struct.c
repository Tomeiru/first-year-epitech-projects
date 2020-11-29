/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** ini_struct
*/

#include "my_hunter.h"

struct game_struct *ini_game_struct(void)
{
    struct game_struct *game_man = malloc(sizeof(struct game_struct));
    game_man->game_stats = ini_stats_struct();
    game_man->game_gui = ini_gui_struct();
    game_man->game_birds = ini_birds_struct();

    return (game_man);
}

struct stats *ini_stats_struct(void)
{
    struct stats *game_stats = malloc(sizeof(struct stats));

    game_stats->score = 0;
    game_stats->high_score = 0;
    game_stats->shots = 0;
    game_stats->phase = 0;
    game_stats->round = 1;
    game_stats->act_speed = 5;
    game_stats->score_this_round = 0;
    game_stats->missed = 0;
    game_stats->game_over_sound_played = 0;
    game_stats->game_menu_sound_played = 0;
    return (game_stats);
}

struct gui *ini_gui_struct(void)
{
    struct gui *game_gui = malloc(sizeof(struct gui));

    game_gui->rect_second.top = 0;
    game_gui->rect_second.left = 1024;
    game_gui->rect_second.width = 1024;
    game_gui->rect_second.height = 960;
    return (game_gui);
}

struct birds *ini_birds_struct(void)
{
    struct birds *game_birds = malloc(sizeof(struct birds));

    game_birds->sprite_pos.x = 0;
    game_birds->sprite_pos.y = 0;
    game_birds->need_spawn = 1;
    game_birds->which_bird = 0;
    return (game_birds);
}