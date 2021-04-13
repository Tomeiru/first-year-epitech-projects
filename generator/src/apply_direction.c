/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** apply_direction
*/

#include "generator.h"

void apply_up(info_t *info_struct)
{
    info_struct->maze[info_struct->current_y - 1]
    [info_struct->current_x] = '*';
    info_struct->maze[info_struct->current_y - 2]
    [info_struct->current_x] = '*';
    info_struct->current_y -= 2;
}

void apply_down(info_t *info_struct)
{
    info_struct->maze[info_struct->current_y + 1]
    [info_struct->current_x] = '*';
    info_struct->maze[info_struct->current_y + 2]
    [info_struct->current_x] = '*';
    info_struct->current_y += 2;
}

void apply_left(info_t *info_struct)
{
    info_struct->maze[info_struct->current_y]
    [info_struct->current_x - 1] = '*';
    info_struct->maze[info_struct->current_y]
    [info_struct->current_x - 2] = '*';
    info_struct->current_x -= 2;
}

void apply_right(info_t *info_struct)
{
    info_struct->maze[info_struct->current_y]
    [info_struct->current_x + 1] = '*';
    info_struct->maze[info_struct->current_y]
    [info_struct->current_x + 2] = '*';
    info_struct->current_x += 2;
}

void apply_direction(info_t *info_struct, int direction)
{
    void (* apply_dir[4])(info_t *) = {
        apply_up, apply_down, apply_left, apply_right
    };

    apply_dir[direction](info_struct);
    if (info_struct->cell_visited == 1)
        add_end_first(info_struct, &info_struct->head, &info_struct->last);
    else
        add_end(info_struct, &info_struct->last);
    info_struct->cell_visited += 1;
}