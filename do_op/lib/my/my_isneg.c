/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** my_isneg
*/

#include "my.h"

int my_isneg(int n)
{
    char N = 'N';
    char P = 'P';

    if (n >= 0) {
        my_putchar(P);
    }

    else {
        my_putchar(N);
    }
}
