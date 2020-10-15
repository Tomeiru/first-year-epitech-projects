/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** error
*/

#include "infinadd.h"
#include "my.h"

int error (int ac, char **av)
{
    if (is_valid_num(av[1]) == 0 || is_valid_num(av[2]) == 0)
        return (84);
    if (av[1][0] == '\0' || av[2][0] == '\0')
        return (84);
    if (ac != 3)
        return (84);
    return (0);
}