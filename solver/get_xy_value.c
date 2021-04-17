/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_xy_value
*/

#include "solver.h"

int get_x_value(char *maze_str)
{
    int idx = 0;

    for ( ; maze_str[idx] != '\n' && maze_str[idx] != '\0'; idx++);
    return (idx);
}

int get_y_value(char *maze_str)
{
    int ret = 1;

    for (int i = 0; maze_str[i]; i++)
        if (maze_str[i] == '\n')
            ret++;
    return (ret);
}