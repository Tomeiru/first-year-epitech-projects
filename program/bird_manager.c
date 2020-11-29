/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** bird_manager
*/

#include "my_hunter.h"

void roll_pos(struct game_struct *game_man)
{
    srand(time(0));
    int y = rand()%675;

    game_man->game_birds->sprite_pos.x = 0;
    game_man->game_birds->sprite_pos.y = y;
    sfSprite_setPosition(game_man->game_birds->sprite,
    game_man->game_birds->sprite_pos);
}

void roll_difficulty(struct game_struct *game_man)
{
    srand(time(0));
    int nb_bird = rand()%3;

    game_man->game_birds->which_bird = nb_bird;
    if (game_man->game_birds->which_bird == 0) {
        game_man->game_birds->rect.top = 272;
        game_man->game_birds->speed = 0.5;
    }
    if (game_man->game_birds->which_bird == 1) {
        game_man->game_birds->rect.top = 0;
        game_man->game_birds->speed = 1;
    }
    if (game_man->game_birds->which_bird == 2) {
        game_man->game_birds->rect.top = 136;
        game_man->game_birds->speed = 1.5;
    }
    game_man->game_birds->rect.left = 0;
    game_man->game_birds->rect.width = 136;
    game_man->game_birds->rect.height = 136;
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

void bird_manager(struct game_struct *game_man, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    double seconds = time.microseconds / 1000000.0;

    if (game_man->game_birds->need_spawn == 1) {
        roll_pos(game_man);
        roll_difficulty(game_man);
        game_man->game_stats->bird_this_round += 1;
        game_man->game_birds->need_spawn = 0;
    }
    if (game_man->game_birds->need_spawn == 0) {
        if (seconds > 0.125) {
            sfSprite_move(game_man->game_birds->sprite,
            coord_to_pos(game_man->game_birds->speed *
            game_man->game_stats->act_speed, 0));
            move_rect(&game_man->game_birds->rect, 136, 544);
            sfClock_restart(clock);
        }
    }
    if (sfSprite_getPosition(game_man->game_birds->sprite).x > 1024)
        missed(game_man);
}

void missed(struct game_struct *game_man)
{
    game_man->game_stats->missed += 1;
    game_man->game_birds->need_spawn = 1;
}

void touched(struct game_struct *game_man)
{
    sfSound_play(game_man->game_gui->touched);
    game_man->game_stats->killed += 1;
    game_man->game_stats->phase = 3;
    game_man->game_birds->need_spawn = 1;
}