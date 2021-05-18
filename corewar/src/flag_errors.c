/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** file_errors
*/

#include "corewar.h"

int check_flag(char *str, char *nbr, int len)
{
    if ((len != 2 && len != 5) || (my_strcmp(str, "-dump") == 0 &&
    my_strcmp(str, "-n") == 0 && my_strcmp(str, "-a") == 0))
        return (84);
    else if (my_strcmp(str, "-dump") == 1 && my_str_ishexa(nbr) == 0)
        return (84);
    else
        if (my_strcmp(str, "-n") == 1 || my_strcmp(str, "-a") == 1
        && my_str_isnum(nbr) == 0)
            return (84);
    return (0);
}

int flag_errors(int ac, char **av)
{
    int result = 0;

    for (int i = 1; i != ac; i++) {
        if (av[i][0] == '-')
            result = check_flag(av[i], av[i + 1], my_strlen(av[i]));
        if (result == 84)
            return (84);
    }
    return (0);
}