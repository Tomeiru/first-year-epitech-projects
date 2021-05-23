/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** file_errors
*/

#include "corewar.h"

int check_flag(char **av, int i, int len)
{
    if (av[i + 1] == NULL)
        return (84);
    if ((len != 2 && len != 5) || (my_strcmp(av[i], "-dump") != 0 &&
    my_strcmp(av[i], "-n") != 0 && my_strcmp(av[i], "-a") != 0))
        return (84);
    if (my_strcmp(av[i], "-dump") == 0 && my_str_ishexa(av[i + 1]) == 0)
        return (84);
    if (my_strcmp(av[i], "-n") == 0 && (my_strcmp(av[i + 1], "1") == 0 ||
    my_strcmp(av[i + 1], "2") == 0 || my_strcmp(av[i + 1], "3") == 0 ||
    my_strcmp(av[i + 1], "4") == 0) && (av[i + 2] == NULL ||
    (my_strcmp(av[i + 2], "-a") != 0 && check_cor(".cor", av[i + 2]) == 1)))
        return (84);
    if ((my_strcmp(av[i], "-a") == 0 && my_str_isnum(av[i + 1]) == 0) &&
    (av[i + 2] == NULL || (my_strcmp(av[i + 2], "-n") != 0 &&
    check_cor(".cor", av[i + 2]) == 1)))
        return (84);
    return (0);
}

int flag_errors(int ac, char **av)
{
    int result = 0;

    for (int i = 1; i != ac; i++) {
        if (av[i][0] == '-')
            result = check_flag(av, i, my_strlen(av[i]));
        if (result == 84)
            return (84);
    }
    return (0);
}