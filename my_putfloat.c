/*
** EPITECH PROJECT, 2020
** my_putfloat
** File description:
** my_putfloat
*/

#include "proto.h"

int my_putfloat(int ltr, int ltr_max)
{
    int f = (ltr * 10000 / ltr_max);
    int dec = f % 100;
    int val = f / 100;

    my_putchar(' ');
    my_putchar('(');
    my_put_nbr(val);
    my_putchar('.');
    if (dec < 10 && dec != 0)
        my_putchar('0');
    my_put_nbr(dec);
    if (dec == 0)
        my_putchar('0');
    my_putchar('%');
    my_putchar(')');
}