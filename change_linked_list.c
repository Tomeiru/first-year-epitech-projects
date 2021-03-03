/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-mathieu.brujan
** File description:
** change_linked_list
*/

#include "my_sokoban.h"

void change_linked_list_down(struct game_struct *game, struct node *head_boxes)
{
    while (game->cursor_x - game->x_to_center != head_boxes->x &&
    game->cursor_y - game->y_to_center + 1 != head_boxes->y)
        head_boxes = head_boxes->next;
    head_boxes->y += 1;
}

void change_linked_list_up(struct game_struct *game, struct node *head_boxes)
{
    while (game->cursor_x - game->x_to_center != head_boxes->x &&
    game->cursor_y - game->y_to_center - 1 != head_boxes->y)
        head_boxes = head_boxes->next;
    head_boxes->y -= 1;
}

void change_linked_list_left(struct game_struct *game, struct node *head_boxes)
{
    while (game->cursor_x - 1 - game->x_to_center != head_boxes->x &&
    game->cursor_y - game->y_to_center != head_boxes->y)
        head_boxes = head_boxes->next;
    head_boxes->x -= 1;
}

void change_linked_list_right(struct game_struct *game, struct node *head_boxes)
{
    while (game->cursor_x + 1 - game->x_to_center != head_boxes->x &&
    game->cursor_y - game->y_to_center != head_boxes->y)
        head_boxes = head_boxes->next;
    head_boxes->x += 1;
}