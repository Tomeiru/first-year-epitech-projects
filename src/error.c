/*
** EPITECH PROJECT, 2021
** 110borwein
** File description:
** error
*/

#include "borwein.h"

void error(int ac, char **av)
{
    if (ac != 2)
        exit(84);
    for (int i = 0; av[1][i]; i++)
        if (!(av[1][i] >= '0' && av[1][i] <= '9'))
            exit(84);
}