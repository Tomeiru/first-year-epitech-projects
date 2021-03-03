/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-mathieu.brujan
** File description:
** run_game
*/

#include "my_sokoban.h"

void input_gestion(struct game_struct *game, struct node *head_boxes)
{
    int ch = getch();

    switch (ch) {
        case KEY_UP :
            key_up_gestion(game, head_boxes);
            break;
        case KEY_DOWN :
            key_down_gestion(game, head_boxes);
            break;
        case KEY_LEFT :
            key_left_gestion(game, head_boxes);
            break;
        case KEY_RIGHT :
            key_right_gestion(game, head_boxes);
            break;
    }
}

void print_map(struct game_struct *game)
{
    for (int y = 0; game->map_arr[y]; y++) {
        move(game->cursor_y++, game->x_to_center);
        for (int x = 0; game->map_arr[y][x]; x++) {
            addch(game->map_arr[y][x]);
            game->cursor_x++;
            init_p(game, y, x);
        }game->cursor_x = game->x_to_center;
    }move(game->initial_p_y, game->initial_p_x);
    game->cursor_x = game->initial_p_x;
    game->cursor_y = game->initial_p_y;
}

void run_game(struct game_struct *game, struct node *head_boxes,
struct node *head_storages)
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    get_window_info(game);
    while (1) {
        if (game->reset == 0) {
            print_map(game);
            game->reset = 1;
        }input_gestion(game, head_boxes);
        check_win_or_lose(game, head_boxes, head_storages);
        refresh();
    }endwin();
}