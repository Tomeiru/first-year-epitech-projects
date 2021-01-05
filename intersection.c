/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** 101pong
*/

#include "intersection.h"

int intersection(int ac, char **av)
{
    error(ac, av);
    if (av[1][0] == '1')
        sphere_func(av);
    if (av[1][0] == '2')
        cylinder_func(av);
    if (av[1][0] == '3')
        cone_func(av);
    return (0);
}