/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-mathieu.brujan
** File description:
** game_fourth
*/

#include "my_runner.h"

void check_collision(struct game_struct *game_man)
{
    if (game_man->game_stats->is_jumping == 1 && game_man->game_stats->invicible == 0)
        jump_check(game_man);
    if (game_man->game_stats->is_jumping == 0 && game_man->game_stats->invicible == 0)
        run_check(game_man);
}

void draw_score(sfRenderWindow *window, struct game_struct *game_man)
{
    sfRenderWindow_drawText(window, game_man->game_gui->score, NULL);
    sfRenderWindow_drawText(window, game_man->game_gui->score_value, NULL);
    sfRenderWindow_drawSprite(window, game_man->game_gui->crown, NULL);
    sfText_setString(game_man->game_gui->hscore_value, print_u(game_man->game_stats->high_score));
    sfRenderWindow_drawText(window, game_man->game_gui->hscore_value, NULL);
}

void main_game(sfRenderWindow *window, struct game_struct *game_man)
{
    sfRenderWindow_clear(window, sfBlack);
    sfText_setString(game_man->game_gui->score_value,
    print_u(game_man->game_stats->score));
    if (game_man->game_audio->theme_song_launched == 0) {
        sfSound_play(game_man->game_audio->theme_song);
        game_man->game_audio->theme_song_launched = 1;
    }
    obstacle_manager(game_man);
    draw_sprite(window, game_man);
    draw_score(window, game_man);
    check_collision(game_man);
    sfRenderWindow_display(window);
}

void game_over_window(sfRenderWindow *window, struct game_struct *game_man)
{
    if (game_man->game_stats->phase != 10)
        return;
    sfSound_stop(game_man->game_audio->theme_song);
    sfRenderWindow_drawSprite(window, game_man->game_gui->game_over, NULL);
    if (game_man->game_stats->score > game_man->game_stats->high_score)
        game_man->game_stats->high_score = game_man->game_stats->score;
    draw_score(window, game_man);
    sfRenderWindow_display(window);
}

void phase_manager(sfRenderWindow *window, struct game_struct *game_man,
sfClock *clock)
{
    if (game_man->game_stats->phase == 0)
        main_game(window, game_man);
    if (game_man->game_stats->phase == 10)
        game_over_window(window, game_man);
}