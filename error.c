/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

#include "proto.h"

int error (int ac, char **av)
{
    if (av[1][0] == '\0')
        return (84);
    for (int j = 0; av[1][j]; j++)
        if (my_str_isnotalpha(av[1]) == 1)
            return (84);
    for (int i = 2; av[i][0]; i++) {
        if (my_ltr_isalpha(av[i][0]) == 0)
            return(84);
        if (av[i][1] != '\0')
            return (84);
    return (0);
    }
}