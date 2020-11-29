/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** game_second
*/

#include "my_hunter.h"

void next_round(struct game_struct *game_man)
{
    sfSound_play(game_man->game_gui->round_win);
    game_man->game_stats->score_this_round = 0;
    game_man->game_stats->round += 1;
    game_man->game_stats->bird_this_round = 0;
    game_man->game_stats->act_speed *= 1.5;
    game_man->game_stats->missed = 0;
}

void round_complete(struct game_struct *game_man)
{
    if (game_man->game_stats->score_this_round < 5)
        game_man->game_stats->phase = 10;
    else
        next_round(game_man);
    
}

void red_bird(sfRenderWindow *window, struct game_struct *game_man)
{
    sfIntRect green_ducks = {384, 964, 28 *
    game_man->game_stats->score_this_round + 4 *
    (game_man->game_stats->score_this_round - 1), 28};
    sfIntRect red_ducks = {1408, 964, 28 * game_man->game_stats->missed + 4 *
    (game_man->game_stats->missed - 1), 28};
    sfVector2f pos_green = {416, 836};
    sfVector2f pos_red ={736 - (32 * game_man->game_stats->missed), 836};

    if (game_man->game_stats->score_this_round == 0)
        return;
    sfSprite_setPosition(game_man->game_gui->red_duck, pos_red);
    sfSprite_setPosition(game_man->game_gui->green_duck, pos_green);
    sfSprite_setTextureRect(game_man->game_gui->red_duck, red_ducks);
    sfSprite_setTextureRect(game_man->game_gui->green_duck, green_ducks);
    sfRenderWindow_drawSprite(window, game_man->game_gui->red_duck, NULL);
    sfRenderWindow_drawSprite(window, game_man->game_gui->green_duck, NULL);
}

void alt_game(sfRenderWindow *window, struct game_struct *game_man,
sfClock *clock)
{
    if (game_man->game_stats->phase != 2)
        return;
    sfRenderWindow_drawSprite(window, game_man->game_gui->background, NULL);
    score_manager(window, game_man);
    red_bird(window, game_man);
    bird_manager(game_man, clock);
    if (game_man->game_stats->bird_this_round == 10)
        round_complete(game_man);
    sfSprite_setTextureRect(game_man->game_birds->sprite,
    game_man->game_birds->rect);
    sfRenderWindow_drawSprite(window, game_man->game_birds->sprite, NULL);
    crosshair_manager(window, game_man);
    sfRenderWindow_display(window);
}

void killed(sfRenderWindow *window, struct game_struct *game_man, 
sfClock *clock)
{
    if (game_man->game_stats->phase != 3)
        return;
    game_man->game_birds->rect.left = 544;
    sfSprite_setTextureRect(game_man->game_birds->sprite,
    game_man->game_birds->rect);
    sfRenderWindow_drawSprite(window, game_man->game_birds->sprite, NULL);
    crosshair_manager(window, game_man);
    sfRenderWindow_display(window);
    game_man->game_stats->score += 1;
    game_man->game_stats->score_this_round += 1;
    game_man->game_stats->phase = 2;
}