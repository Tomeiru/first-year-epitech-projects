/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-mathieu.brujan
** File description:
** check_win_or_lose
*/

#include "my_sokoban.h"

int lose_condition(struct game_struct *game, struct node *head_boxes)
{
    if (game->map_arr[head_boxes->y][head_boxes->x - 1] == 'X' ||
    game->map_arr[head_boxes->y][head_boxes->x - 1] == '#'||
    game->map_arr[head_boxes->y][head_boxes->x + 1] == 'X' ||
    game->map_arr[head_boxes->y][head_boxes->x + 1] == '#')
        if (game->map_arr[head_boxes->y - 1][head_boxes->x] == 'X' ||
    game->map_arr[head_boxes->y - 1][head_boxes->x] == '#' ||
    game->map_arr[head_boxes->y + 1][head_boxes->x] == 'X' ||
    game->map_arr[head_boxes->y + 1][head_boxes->x] == '#')
            return (1);
    return (0);
}

void check_lose(struct game_struct *game, struct node *head_boxes)
{
    int idx = head_boxes->idx;

    if (lose_condition(game, head_boxes) == 0)
        return;
    head_boxes = head_boxes->next;
    while (head_boxes->idx != idx) {
        if (lose_condition(game, head_boxes) == 0)
            return;
        head_boxes = head_boxes->next;
    }endwin();
    exit(1);
}

void check_win_or_lose(struct game_struct *game, struct node *head_boxes,
struct node *head_storages)
{
    check_lose(game, head_boxes);
}