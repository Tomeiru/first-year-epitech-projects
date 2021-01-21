/*
** EPITECH PROJECT, 2020
** my_putnbr_err
** File description:
** displays number given to it as parameter in error channel
*/

#include "my.h"

int my_putnbr_err(int nb)
{
    int div = 1;
    int count = 0;

    if (nb < 0) {
        my_putchar_err('-');
        nb = nb * -1;
        count++;
    }
    for ( ; (nb/div) >= 10; div *= 10);
    for ( ; div > 0; div /= 10) {
        my_putchar_err((nb/div) % 10 + 48);
        count++;
    }
    return (count);
}