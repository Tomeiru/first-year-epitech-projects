/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** game_third
*/

#include "my_hunter.h"

void main_menu(sfRenderWindow *window, struct game_struct *game_man)
{
    if (game_man->game_stats->phase != 0) {
        sfRenderWindow_clear(window, sfBlack);
        return;
    }
    if (game_man->game_stats->game_menu_sound_played == 0) {
        sfSound_play(game_man->game_gui->game_menu_sound);
        game_man->game_stats->game_menu_sound_played = 1;
    }
    sfRenderWindow_drawSprite(window, game_man->game_gui->menu, NULL);
    sfRenderWindow_display(window);
}

void main_game(sfRenderWindow *window, struct game_struct *game_man,
sfClock *clock)
{
    if (game_man->game_stats->phase != 1) {
        sfRenderWindow_clear(window, sfBlack);
        return;
    }
    sfSprite_setTextureRect(game_man->game_gui->background,
    game_man->game_gui->rect_second);
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

void score_manager(sfRenderWindow *window, struct game_struct *game_man)
{
    if (game_man->game_stats->score > 999999)
        game_man->game_stats->score = 999999;
    if (game_man->game_stats->high_score > 999999)
        game_man->game_stats->high_score = 999999;
    load_text_score(game_man);
    load_text_round(game_man);
    sfRenderWindow_drawText(window, game_man->game_gui->score, NULL);
    sfRenderWindow_drawText(window, game_man->game_gui->high_score, NULL);
    sfRenderWindow_drawText(window, game_man->game_gui->round, NULL);
}

void crosshair_manager(sfRenderWindow *window, struct game_struct *game_man)
{
    sfVector2f cursor_position;

    cursor_position.x = sfMouse_getPositionRenderWindow(window).x - 50;
    cursor_position.y = sfMouse_getPositionRenderWindow(window).y - 46;
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sfSprite_setPosition(game_man->game_gui->crosshair, cursor_position);
    sfRenderWindow_drawSprite(window, game_man->game_gui->crosshair, NULL);
}

void restart(struct game_struct *game_man)
{
    game_man->game_stats->phase = 2;
    game_man->game_stats->high_score = game_man->game_stats->score;
    game_man->game_stats->score_this_round = 0;
    game_man->game_stats->score = 0;
    game_man->game_stats->round = 1;
    game_man->game_birds->need_spawn = 1;
    game_man->game_stats->act_speed = 5;
    game_man->game_stats->bird_this_round = 0;
    game_man->game_stats->missed = 0;
    game_man->game_stats->game_over_sound_played = 0;
    game_man->game_stats->game_menu_sound_played = 0;
}