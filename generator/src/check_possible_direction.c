/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_possible_direction
*/

#include "generator.h"

static int check_up(info_t *info_struct)
{
    if (info_struct->current_y < 2)
        return (0);
    if (info_struct->maze[info_struct->current_y - 2]
    [info_struct->current_x] != 'X')
        return (0);
    info_struct->direction[0] = '1';
    return (1);
}

static int check_down(info_t *info_struct)
{
    if (info_struct->current_y > info_struct->y - 3)
        return (0);
    if (info_struct->maze[info_struct->current_y + 2]
    [info_struct->current_x] != 'X')
        return (0);
    info_struct->direction[1] = '1';
    return (1);
}

static int check_left(info_t *info_struct)
{
    if (info_struct->current_x < 2)
        return (0);
    if (info_struct->maze[info_struct->current_y]
    [info_struct->current_x - 2] != 'X')
        return (0);
    info_struct->direction[2] = '1';
    return (1);
}

static int check_right(info_t *info_struct)
{
    if (info_struct->current_x > info_struct->x - 3)
        return (0);
    if (info_struct->maze[info_struct->current_y]
    [info_struct->current_x + 2] != 'X')
        return (0);
    info_struct->direction[3] = '1';
    return (1);
}

int check_possible_direction(info_t *info_struct)
{
    int (* check_dir[4])(info_t *) = {
        check_up, check_down, check_left, check_right
    };
    int number_dir = 0;

    for (int i = 0; info_struct->direction[i]; i++)
        info_struct->direction[i] = '0';
    for (int i = 0; i < 4; i++) {
        if (check_dir[i](info_struct) == 1)
            number_dir += 1;
    } return (number_dir);
}