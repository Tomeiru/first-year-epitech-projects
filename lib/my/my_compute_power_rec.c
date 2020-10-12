/*
** EPITECH PROJECT, 2020
** my_compute_power
** File description:
** my_compute_power
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    long res = 0;

    if (res > 2147483647 || res > 2147483647)
        return (0);
    if (res < -2147483647 || res < -2147483647)
        return (0);
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);

    res = nb * my_compute_power_rec(nb, p - 1);

    return ((int)res);
}
