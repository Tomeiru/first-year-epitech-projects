/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-mathieu.brujan
** File description:
** game_third
*/

#include "my_runner.h"

void draw_mario(sfRenderWindow *window, struct game_struct *game_man)
{
    sfSprite_setTextureRect(game_man->game_gui->jumping_mario,
    game_man->game_gui->jumping_mario_rect);
    sfSprite_setTextureRect(game_man->game_gui->mario,
    game_man->game_gui->mario_rect);
    if (game_man->game_stats->is_jumping == 0)
        sfRenderWindow_drawSprite(window, game_man->game_gui->mario, NULL);
    else
        sfRenderWindow_drawSprite(window, game_man->game_gui->jumping_mario,
         NULL);
}

void draw_sprite(sfRenderWindow *window, struct game_struct *game_man)
{
    sfSprite_setTextureRect(game_man->game_gui->background,
    game_man->game_gui->bg_rect);
    sfRenderWindow_drawSprite(window, game_man->game_gui->background, NULL);
    ground_generator(window, game_man);
    movement(window, game_man);
    draw_mario(window, game_man);
    sfSprite_setTextureRect(game_man->game_gui->obstacle,
    game_man->game_gui->obstacle_rect);
    sfRenderWindow_drawSprite(window, game_man->game_gui->obstacle, NULL);
    lives(window, game_man);
}

void touched(struct game_struct *game_man)
{
    game_man->game_stats->lives -= 1;
    game_man->game_stats->invicible = 1;
    game_man->game_stats->ouch = 1;
    if (game_man->game_stats->lives == 0)
        game_man->game_stats->phase = 10;
}

void jump_check(struct game_struct *game_man)
{
    int obstacle_x = sfSprite_getPosition(game_man->game_gui->obstacle).x;
    int obstacle_y = sfSprite_getPosition(game_man->game_gui->obstacle).y;
    int jumping_mario_x = sfSprite_getPosition(game_man->game_gui->jumping_mario).x;
    int jumping_mario_y = sfSprite_getPosition(game_man->game_gui->jumping_mario).y;

    if (!((jumping_mario_x + 88 < obstacle_x) || (jumping_mario_x > obstacle_x + 48)))
        if (!((jumping_mario_y + 144 < obstacle_y) || (jumping_mario_y > obstacle_y + 48)))
            touched(game_man);
}

void run_check (struct game_struct *game_man)
{
    int obstacle_x = sfSprite_getPosition(game_man->game_gui->obstacle).x;
    int obstacle_y = sfSprite_getPosition(game_man->game_gui->obstacle).y;
    int mario_x = sfSprite_getPosition(game_man->game_gui->mario).x;
    int mario_y = sfSprite_getPosition(game_man->game_gui->mario).y;

    if (!((mario_x + 122 < obstacle_x) || (mario_x > obstacle_x + 48)))
        if (!((mario_y + 144 < obstacle_y) || (mario_y > obstacle_y + 48)))
            touched(game_man);
}
