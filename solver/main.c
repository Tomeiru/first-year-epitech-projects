/*
** EPITECH PROJECT, 2021
** Temp
** File description:
** main
*/

#include "solver.h"

int main(int ac, char **av)
{
    info_t *info_struct;
    char *maze_str;
    int len = 0;

    error_arg(ac);
    maze_str = file_reader(av[1], &len);
    info_struct = create_and_fill_struct(maze_str, len);
    srand(time(NULL));
    info_struct->maze[0][0] = 'o';
    solver(info_struct);
    return (0);
}