/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include "doop.h"

int error(int ac, char **av)
{
    if (ac < 4 || ac > 4)
        return (85);
    if (is_op(av[2]) == 0)
        return (84);
    if (is_op(av[2]) == 99 && my_getnbr(av[3]) == 0)
        return (84);
    if (has_nbr(av[1]) == 0 || has_nbr(av[3]) == 0)
        return (84);
    return (0);
}