/*
** EPITECH PROJECT, 2021
** Temp
** File description:
** generator
*/

#include "generator.h"

void generator(info_t *info_struct)
{
    if (info_struct->perfect == 1)
        generate_perfect_maze(info_struct);
    else
        generate_imperfect_maze(info_struct);
    for (int i = 0; info_struct->maze[i]; i++) {
        if (info_struct->maze[i + 1] == NULL)
            printf("%s", info_struct->maze[i]);
        else
            printf("%s\n", info_struct->maze[i]);
    }
}