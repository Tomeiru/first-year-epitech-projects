/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** generate_imperfect_maze
*/

#include "generator.h"

void generate_imperfect_maze(info_t *info_struct)
{
    int random_line = 0;
    int nb_wall = 0;
    int random_wall = 0;

    generate_perfect_maze(info_struct);
    random_line = rand() % info_struct->y;
    for (int i = 0; info_struct->maze[random_line][i]; i++)
        if (info_struct->maze[random_line][i] == 'X')
            nb_wall++;
    random_wall = rand() % nb_wall;
    nb_wall = 0;
    for (int i = 0; info_struct->maze[random_line][i]; i++) {
        if (info_struct->maze[random_line][i] == 'X')
            nb_wall++;
        if (random_wall == nb_wall) {
            info_struct->maze[random_line][i] = '*';
            break;
        }
    }
}
