/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** game
*/

#include "my_hunter.h"

/*void close_game(sfRenderWindow *window, struct game_struct *game_man)
{
    sfSprite_destroy(game_man->game_gui->crosshair);
    sfSprite_destroy(game_man->game_gui->red_duck);
    sfSprite_destroy(game_man->game_gui->green_duck);
    sfSprite_destroy(game_man->game_gui->background);
    sfSprite_destroy(game_man->game_gui->menu);
    sfSound_destroy(game_man->game_gui->gun_shot);
    sfSound_destroy(game_man->game_gui->round_win);
    sfSound_destroy(game_man->game_gui->game_over_sound);
    sfSound_destroy(game_man->game_gui->game_menu_sound);
    sfSound_destroy(game_man->game_gui->touched);
    sfText_destroy(game_man->game_gui->score);
    sfText_destroy(game_man->game_gui->high_score);
    sfText_destroy(game_man->game_gui->round);
    sfText_destroy(game_man->game_gui->new_hs);
    sfText_destroy(game_man->game_gui->sn_end);
    sfText_destroy(game_man->game_gui->s_end);
    sfText_destroy(game_man->game_gui->game_over);
    sfText_destroy(game_man->game_gui->end_text);
    sfFont_destroy(game_man->game_gui->font);
    sfRenderWindow_close(window);
}*/

void game_over_window(sfRenderWindow *window, struct game_struct *game_man)
{
    if (game_man->game_stats->phase != 10)
        return;
    if (game_man->game_stats->game_over_sound_played == 0) {
        sfSound_play(game_man->game_gui->game_over_sound);
        game_man->game_stats->game_over_sound_played = 1;
    }
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawText(window, game_man->game_gui->game_over, NULL);
    if (game_man->game_stats->score > game_man->game_stats->high_score)
        sfRenderWindow_drawText(window, game_man->game_gui->new_hs, NULL);
    sfRenderWindow_drawText(window, game_man->game_gui->s_end, NULL);
    sfText_setString(game_man->game_gui->sn_end,
    print_di(game_man->game_stats->score));
    sfRenderWindow_drawText(window, game_man->game_gui->sn_end, NULL);
    sfRenderWindow_drawText(window, game_man->game_gui->end_text, NULL);
    sfRenderWindow_display(window);
}

void phase_manager(sfRenderWindow *window, struct game_struct *game_man,
sfClock *clock)
{
    if (game_man->game_stats->phase == 0)
        main_menu(window, game_man);
    if (game_man->game_stats->phase == 1)
        main_game(window, game_man, clock);
    if (game_man->game_stats->phase == 2)
        alt_game(window, game_man, clock);
    if (game_man->game_stats->phase == 3)
        killed(window, game_man, clock);
    if (game_man->game_stats->phase == 10)
        game_over_window(window, game_man);
}


void analyse_events(sfRenderWindow *window, sfEvent event,
struct game_struct *game_man)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (if_conditions(event, game_man) == 1)
        game_man->game_stats->phase += 1;
    if (if_conditions(event, game_man) == 2)
        game_man->game_stats->phase += 2;
    if (if_conditions(event, game_man) == 3)
        shot(game_man, window);
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyQ)
        sfRenderWindow_close(window);
    if (game_man->game_stats->phase == 10 && event.type == sfEvtKeyReleased &&
    event.key.code == sfKeyR)
        restart(game_man);
}

int run_game(sfRenderWindow *window)
{
    struct game_struct *game_man = ini_game_struct();
    sfClock *clock = sfClock_create();
    sfIntRect rect = {0, 0, 1024, 960};
    sfEvent event;

    load_files(game_man);
    while (sfRenderWindow_isOpen(window)) {
        while(sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, game_man);
        phase_manager(window, game_man, clock);
    }
}

int game(void)
{
    sfVideoMode mode = {1024, 960, 32};
    char *name = "Hunter!";
    sfRenderWindow* window;
    window = sfRenderWindow_create(mode, name, sfDefaultStyle, NULL);
    run_game(window);
    return (0);
}