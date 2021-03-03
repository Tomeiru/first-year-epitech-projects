/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-mathieu.brujan
** File description:
** input_gestion
*/

#include "my_sokoban.h"

void is_it_O(struct game_struct *game)
{
    if (game->edited_map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'O')
        addch('O');
    else
        addch(' ');
}

void key_up_gestion(struct game_struct *game, struct node *head_boxes)
{
    if (condition_up(game) == 1)
        return;
    is_it_O(game);
    if (game->map_arr[game->cursor_y - 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'X') {
        change_linked_list_up(game, head_boxes);
        game->map_arr[game->cursor_y - 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] = ' ';
        game->map_arr[game->cursor_y - 2 - game->y_to_center]
    [game->cursor_x - game->x_to_center] = 'X';
        move(game->cursor_y - 2, game->cursor_x);
        addch('X');
    }game->cursor_y--;
    move(game->cursor_y, game->cursor_x);
    addch('P');
    move(game->cursor_y, game->cursor_x);
}

void key_down_gestion(struct game_struct *game, struct node *head_boxes)
{
    if (condition_down(game) == 1)
        return;
    is_it_O(game);
    if (game->map_arr[game->cursor_y + 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] == 'X') {
        change_linked_list_down(game, head_boxes);
        game->map_arr[game->cursor_y + 1 - game->y_to_center]
    [game->cursor_x - game->x_to_center] = ' ';
        game->map_arr[game->cursor_y + 2 - game->y_to_center]
    [game->cursor_x - game->x_to_center] = 'X';
        move(game->cursor_y + 2, game->cursor_x);
        addch('X');
    }game->cursor_y++;
    move(game->cursor_y, game->cursor_x);
    addch('P');
    move(game->cursor_y, game->cursor_x);
}

void key_left_gestion(struct game_struct *game, struct node *head_boxes)
{
    if (condition_left(game) == 1)
        return;
    is_it_O(game);
    if (game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 1 - game->x_to_center] == 'X') {
        change_linked_list_left(game, head_boxes);
        game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 1 -game->x_to_center] = ' ';
        game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x - 2 - game->x_to_center] = 'X';
        move(game->cursor_y, game->cursor_x - 2);
        addch('X');
    }game->cursor_x--;
    move(game->cursor_y, game->cursor_x);
    addch('P');
    move(game->cursor_y, game->cursor_x);
}

void key_right_gestion(struct game_struct *game, struct node *head_boxes)
{
    if (condition_right(game) == 1)
        return;
    is_it_O(game);
    if (game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 1 - game->x_to_center] == 'X') {
        change_linked_list_right(game, head_boxes);
        game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 1 - game->x_to_center] = ' ';
        game->map_arr[game->cursor_y - game->y_to_center]
    [game->cursor_x + 2 - game->x_to_center] = 'X';
        move(game->cursor_y, game->cursor_x + 2);
        addch('X');
    }game->cursor_x++;
    move(game->cursor_y, game->cursor_x);
    addch('P');
    move(game->cursor_y, game->cursor_x);
}