/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** error
*/

#include "infinadd.h"
#include "my.h"

int is_valid_num(char const *str)
{
    int i = 0;
    int count = 0;
    int minuscount = 0;

    for (i = 0; str[i]; ++i) {
        if ((str[i] < 48 || str[i] > 57) && str[i] != 45)
            count++;
        if (str[i] == 45 && i != 0)
            minuscount++;
    }
    if (count == 0 && minuscount == 0)
        return (1);
    else
        return (0);
}

int error(int ac, char **av)
{
    if (is_valid_num(av[1]) == 0 || is_valid_num(av[2]) == 0)
        return (84);
    if (av[1][0] == '\0' || av[2][0] == '\0')
        return (84);
    if (ac != 3)
        return (84);
    return (0);
}