/*
** EPITECH PROJECT, 2021
** Temp
** File description:
** error
*/

#include "solver.h"

void check_char(char *map)
{
    for (int i = 0; map[i]; i++)
        if (!(map[i] == '*' || map[i] == 'X' || map[i] == '\n'))
            exit(84);
}

void error_arg(int ac)
{
    if (ac != 2)
        exit (84);
}

void error_map(char *map)
{
    check_char(map);
}