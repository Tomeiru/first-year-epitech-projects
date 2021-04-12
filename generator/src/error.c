/*
** EPITECH PROJECT, 2021
** Temp
** File description:
** error
*/

#include "generator.h"

static void check_str_is_num(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            exit(84);
    if (atoi(str) == 0)
        exit(84);
}

static void check_args(int ac, char **av)
{
    for (int i = 1; i < 3; i++)
        check_str_is_num(av[i]);
    if ((ac == 4) && (strcmp(av[3], "perfect") != 0))
        exit(84);
}

void error(int ac, char **av)
{
    if (!(ac == 3 || ac == 4))
        exit(84);
    check_args(ac, av);
}