/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-mathieu.brujan
** File description:
** game
*/

#include "my_runner.h"

sfVector2f coord_to_pos(int x, int y)
{
    sfVector2f position = {x, y};

    return(position);
}

void obstacle_manager(struct game_struct *game_man)
{
    if (game_man->game_stats->need_spawn == 1)
        game_man->game_stats->need_spawn = 0;
    if (sfSprite_getPosition(game_man->game_gui->obstacle).x < -50) {
        sfSprite_setPosition(game_man->game_gui->obstacle, 
        coord_to_pos(1970, 824));
        game_man->game_stats->need_spawn = 1;
        if (game_man->game_stats->ouch == 0) {
            game_man->game_stats->dodge += 1;
            game_man->game_stats->score += 1;
        }game_man->game_stats->ouch = 0;
    }if (game_man->game_stats->dodge == 5) {
        game_man->game_stats->dodge = 0;
        game_man->game_stats->speed += 5;
    }
}

void ground_generator(sfRenderWindow *window, struct game_struct *game_man)
{
    sfSprite_setTextureRect(game_man->game_gui->grass,
    game_man->game_gui->grass_rect);
    sfSprite_setTextureRect(game_man->game_gui->ground,
    game_man->game_gui->ground_rect);
    sfSprite_setTextureRect(game_man->game_gui->underground,
    game_man->game_gui->underground_rect);
    sfSprite_setTextureRect(game_man->game_gui->grass_second,
    game_man->game_gui->grass_second_rect);
    sfSprite_setTextureRect(game_man->game_gui->ground_second,
    game_man->game_gui->ground_second_rect);
    sfSprite_setTextureRect(game_man->game_gui->underground_second,
    game_man->game_gui->underground_second_rect);
    sfRenderWindow_drawSprite(window, game_man->game_gui->ground, NULL);
    sfRenderWindow_drawSprite(window, game_man->game_gui->grass, NULL);
    sfRenderWindow_drawSprite(window, game_man->game_gui->underground, NULL);
}

void movement(sfRenderWindow *window, struct game_struct *game_man)
{
    game_man->game_gui->bg_rect.left += 0.5;
    if (game_man->game_stats->need_spawn == 0)
        sfSprite_move(game_man->game_gui->obstacle, 
        coord_to_pos(-game_man->game_stats->speed, 0));
}

void lives(sfRenderWindow *window, struct game_struct *game_man)
{
    if (game_man->game_stats->lives == 3)
        game_man->game_gui->lives_rect.width = 486;
    if (game_man->game_stats->lives == 2)
        game_man->game_gui->lives_rect.width = 324;
    if (game_man->game_stats->lives == 1)
        game_man->game_gui->lives_rect.width = 162;

    sfSprite_setTextureRect(game_man->game_gui->lives,
    game_man->game_gui->lives_rect);
    sfRenderWindow_drawSprite(window, game_man->game_gui->lives, NULL);
}
