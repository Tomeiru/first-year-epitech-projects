/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-mathieu.brujan
** File description:
** ini_struct
*/

#include "my_sokoban.h"

void set_heigth_and_width(struct game_struct *game)
{
    int width = 0;
    int height = 0;
    int stop = 0;

    for (int i = 0; game->map[i]; i++) {
        if (game->map[i] == '\n') {
            height++;
            stop = 1;
        }if (stop == 0)
            width++;
    }game->width_map = width;
    game->height_map = height;
}

void init_p(struct game_struct *game, int y, int x)
{
    if (game->map_arr[y][x] == 'P') {
        game->initial_p_y = y + game->y_to_center;
        game->initial_p_x = x + game->x_to_center;
    }
}

void get_window_info(struct game_struct *game)
{
    getmaxyx(stdscr, game->height_window, game->width_window);
    game->y_to_center = (game->height_window - game->height_map) / 2;
    game->x_to_center = (game->width_window - game->width_map) / 2;
    game->cursor_y = game->y_to_center;
    game->cursor_x = game->x_to_center;
}

struct game_struct *ini_struct(void)
{
    struct game_struct *game = malloc(sizeof(struct game_struct));

    game->height_map = 0;
    game->width_map = 0;
    game->height_window = 0;
    game->width_window = 0;
    game->need_resize = 0;
    game->cursor_x = 0;
    game->cursor_y = 0;
    game->x_to_center = 0;
    game->y_to_center = 0;
    game->initial_p_x = 0;
    game->initial_p_y = 0;
    game->nb_of_boxes = 0;
    game->reset = 0;
    return (game);
}