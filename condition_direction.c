/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-mathieu.brujan
** File description:
** condition_direction
*/

#include "my_sokoban.h"

int condition_up(struct game_struct *game)
{
    if ((game->map_arr[game->cursor_y - 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == '#') ||
    ((game->map_arr[game->cursor_y - 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'X') &&
    ((game->map_arr[game->cursor_y - 2 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == '#') ||
    (game->map_arr[game->cursor_y - 2 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'X'))))
        return (1);
    else
        return (0);
}

int condition_down(struct game_struct *game)
{
    if ((game->map_arr[game->cursor_y + 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == '#') ||
    ((game->map_arr[game->cursor_y + 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'X') &&
    ((game->map_arr[game->cursor_y + 2 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == '#') ||
    (game->map_arr[game->cursor_y + 2 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'X'))))
        return (1);
    else
        return (0);
}

int condition_left(struct game_struct *game)
{
    if ((game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 1 - game->x_to_center] == '#') ||
    ((game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 1 - game->x_to_center] == 'X') &&
    ((game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 2 - game->x_to_center] == '#' ||
    game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 2 - game->x_to_center] == 'X'))))
        return (1);
    else
        return (0);
}

int condition_right(struct game_struct *game)
{
    if ((game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 1 - game->x_to_center] == '#') ||
    ((game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 1 - game->x_to_center] == 'X') &&
    ((game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 2 - game->x_to_center] == '#') || 
    (game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 2 - game->x_to_center] == 'X'))))
        return (1);
    else
        return (0);
}