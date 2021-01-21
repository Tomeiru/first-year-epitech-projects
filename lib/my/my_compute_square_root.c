/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** returns square root of given number
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    if (nb == 0)
        return (0);
    for (int n = 1; (n * n) <= nb; n++)
        if ((n * n) == nb)
            return (n);
    return (0);
}
