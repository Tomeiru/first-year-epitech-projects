/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-mathieu.brujan
** File description:
** game_fifth
*/

#include "my_runner.h"

void jump(struct game_struct *game_man, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    double seconds = time.microseconds / 1000000.0;

    if (game_man->game_stats->is_jumping != 1)
        return;
    if (seconds > 0.02777 && game_man->game_stats->animation != 17) {
        sfClock_restart(clock);
        game_man->game_stats->animation += 1;
        game_man->game_gui->jumping_mario_rect.left += 89;
        if (game_man->game_stats->animation < 9)
            sfSprite_move(game_man->game_gui->jumping_mario, coord_to_pos(0, -20));
        else
            sfSprite_move(game_man->game_gui->jumping_mario, coord_to_pos(0, 20));
    }
    if (seconds > 0.05) {
        sfSprite_setPosition(game_man->game_gui->jumping_mario, coord_to_pos(200, 720));
        game_man->game_stats->animation = 0;
        game_man->game_gui->jumping_mario_rect.left = 0;
        game_man->game_stats->is_jumping = 0;
        game_man->game_stats->clock_restart = 0;
    }
}

void running(struct game_struct *game_man, sfClock *clock)
{
    game_man->game_stats->animation_run += 1;
    game_man->game_gui->mario_rect.left += 122;
    if (game_man->game_stats->animation_run == 17) {
        game_man->game_stats->animation_run = 0;
        game_man->game_gui->mario_rect.left = 0;
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event,
struct game_struct *game_man, sfClock *clock)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyQ)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
        if (game_man->game_stats->clock_restart == 0) {
            sfClock_restart(clock);
            game_man->game_stats->clock_restart = 1;
            sfSound_play(game_man->game_audio->jump_sound);
        }game_man->game_stats->is_jumping = 1;
    }
}

void immune(struct game_struct *game_man)
{
    sfTime time = sfClock_getElapsedTime(game_man->game_clock->immune);
    double seconds = time.microseconds / 1000000.0;
    if (game_man->game_stats->invicible == 1) {
        if (game_man->game_clock->clock_restarted == 0) {
            sfClock_restart(game_man->game_clock->immune);
            seconds = 0;
            game_man->game_clock->clock_restarted = 1;
        }
        if (seconds > 1) {
            game_man->game_stats->invicible = 0;
            game_man->game_clock->clock_restarted = 0;
        }
    }
}

int run_game(sfRenderWindow *window)
{
    struct game_struct *game_man = ini_game_struct();
    sfClock *clock = sfClock_create();
    sfEvent event;

    load_files(game_man);
    while (sfRenderWindow_isOpen(window)) {
        while(sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, game_man, clock);
        jump(game_man, clock);
        running(game_man, clock);
        immune(game_man);
        phase_manager(window, game_man, clock);
    }
    return (0);
}