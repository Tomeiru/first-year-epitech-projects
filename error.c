/*
** EPITECH PROJECT, 2021
** duo_stumper2
** File description:
** main
*/

#include "stumper.h"
#include <stdlib.h>

char *which_flags(int ac, char **av)
{
    char *flags = create_flags();
    int value = 0;

    for (int i = 1; i < ac; i += 2) {
        value = which_param(av[i]);
        if (flags[value] != '0')
            exit(84);
        flags[value] = i + '0';
    }
    return (flags);
}

void check_wh(char **av, int i)
{
    if (strlen(av[i]) > 2 || strlen(av[i]) == 0)
        exit(84);
    if (av[i][0] < '0' || av[i][0] > '9')
        exit(84);
    if (strlen(av[i]) == 2) 
        if (av[i][1] < '0' || av[i][1] > '9')
            exit(84);
}

void check_pa(char **av, int i)
{
    if (strlen(av[i]) != 1)
        exit(84);
    if (av[i][0] <= 31)
        exit(84);
}

int check_params(int ac, char **av)
{
    char *flags = which_flags(ac, av);

    if (flags[0] != '0')
        check_wh(av, flags[0] + 1 - '0');
    if (flags[1] != '0')
        check_wh(av, flags[1] + 1 - '0');
    if (flags[2] != '0')
        check_pa(av, flags[2] + 1 - '0');
    if (flags[3] != '0')
        check_pa(av, flags[3] + 1 - '0');
    if (flags[4] != '0')
        check_pa(av, flags[4] + 1 - '0');
}

int error(int ac, char **av)
{
    if (ac == 1)
        return (0);
    check_nb_arg(ac);
    check_params(ac, av);
}
