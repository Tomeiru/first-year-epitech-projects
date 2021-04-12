/*
** EPITECH PROJECT, 2021
** Temp
** File description:
** generator
*/

#include "generator.h"

void generate_imperfect_maze(info_t *info_struct)
{
    printf("%s\n", info_struct->maze[0]);
}

void generator(info_t *info_struct)
{
    if (info_struct->perfect == 1)
        generate_perfect_maze(info_struct);
    else
        generate_imperfect_maze(info_struct);
}