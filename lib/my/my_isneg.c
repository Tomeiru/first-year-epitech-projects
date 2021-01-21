/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** outputs N if integer is negative, P if positive or null
*/

#include "my.h"

int my_isneg(int n)
{
    char letter_n = 'N';
    char letter_p = 'P';

    if (n < 0)
        my_putchar(letter_n);
    else if (n >= 0)
        my_putchar(letter_p);
    return (0);
}
