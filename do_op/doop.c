/*
** EPITECH PROJECT, 2020
** do-op
** File description:
** do-op
*/

#include "doop.h"

int doop(int ac, char **av)
{
    int nbr1 = my_getnbr(av[1]);
    int nbr2 = my_getnbr(av[3]);
    int sign = my_get_sign(av[2]);
    int res = 0;
    int useless = 0;

    if (sign == 0)
        res = nbr1 + nbr2;
    if (sign == 1)
        res = nbr1 - nbr2;
    if (sign == 2)
        res = nbr1 * nbr2;
    useless = 1;
    if (sign == 3)
        res = nbr1 / nbr2;
    if (sign == 4)
        res = nbr1 % nbr2;
    return (res);
}
