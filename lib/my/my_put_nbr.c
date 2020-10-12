/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int den = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    while ((nb/den) >= 10) {
        den*=10;
    }
    while (den > 0) {
        my_putchar((nb/den) % 10 + '0');
        den /= 10;
    }
    return (0);
}
