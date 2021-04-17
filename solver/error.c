/*
** EPITECH PROJECT, 2021
** Temp
** File description:
** error
*/

#include "solver.h"

void check_char(char *maze)
{
    for (int i = 0; maze[i]; i++)
        if (!(maze[i] == '*' || maze[i] == 'X' || maze[i] == '\n'))
            exit(84);
}

void error_arg(int ac)
{
    if (ac != 2)
        exit (84);
}

void check_form(int len, int x, int y)
{
    if ((len + 1) % (x + 1) != 0)
        exit(84);
    if ((x + 1) * y != len + 1)
        exit(84);
}

void error_maze(char *maze, int len, int x, int y)
{
    check_char(maze);
    check_form(len, x, y);
    if (maze[0] == 'X' || maze[len - 1] == 'X') {
        write(1, "no solution found\n", 17);
        exit(0);
    }
}