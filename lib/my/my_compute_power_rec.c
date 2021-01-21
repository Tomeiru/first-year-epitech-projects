/*
** EPITECH PROJECT, 2020
** my_computer_power_rec
** File description:
** returns the first argument raised recursively to the power p
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int res;

    if (p == 0)
        return (1);
    else if (p < 0 || p > 2147483647)
        return (0);
    if (p >= 1)
        res = nb * my_compute_power_rec(nb, p - 1);
    return (res);
}
