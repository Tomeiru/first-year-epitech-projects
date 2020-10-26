/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** my_isneg
*/

#include "my.h"

int my_isneg(int n)
{
    char neg = 'N';
    char pos = 'P';

    if (n >= 0) {
        my_putchar(pos);
    }

    else {
        my_putchar(neg);
    }
}
