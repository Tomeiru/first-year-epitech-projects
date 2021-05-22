/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "asm.h"

void my_put_nbr(int nb)
{
    int den = 1;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb/den) >= 10)
        den *= 10;
    while (den > 0) {
        my_putchar((nb/den) % 10 + '0');
        den /= 10;
    }
}
