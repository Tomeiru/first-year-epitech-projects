/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** print_width
*/

#include "my_printf.h"

char *flag_to_number(char *flag)
{
    int i = 0;

    flag = my_revstr(flag);
    for ( ; (flag[i] < '0' || flag[i] > '9') && flag[i] != '\0'; flag++);
    flag = my_revstr(flag);
    for ( ; (flag[i] < '0' || flag[i] > '9') && flag[i] != '\0'; flag++);
    return (flag);
}

void negative_width(char *width_mod, char *print, char *flag)
{
    if ((flag[0] == 'p' || flag[0] == 'i' || flag[0] == 'd') &&
    (width_mod[2] == '1' || width_mod[2] == '2')) {
        if (width_mod[2] == '2' && print[0] != '-')
            my_putchar('+');
        if (width_mod[2] == '1')
            my_putchar(' ');
    }
    if ((flag[0] == 'o' || flag[0] == 'x' || flag[0] == 'X') &&
    (width_mod[0] == '1')) {
        my_putchar('0');
        if (flag[0] == 'x')
            my_putchar('x');
        if (flag[0] == 'X')
            my_putchar('X');
    }
    my_putstr(print);
}

int positive_width(char *width_mod, char *print, char *flag, int nb)
{
    if ((flag[0] == 'p' || flag[0] == 'i' || flag[0] == 'd') &&
    (width_mod[2] == '1' || width_mod[2] == '2')) {
        if (width_mod[2] == '2' && print[0] != '-')
            my_putchar('+');
        if (width_mod[2] == '1')
            my_putchar(' ');
        nb--;
    }
    if ((flag[0] == 'o' || flag[0] == 'x' || flag[0] == 'X') &&
    (width_mod[0] == '1')) {
        my_putchar('0');
        if (flag[0] == 'x')
            my_putchar('x');
        if (flag[0] == 'X')
            my_putchar('X');
        if (flag[0] == 'X' || flag[0] == 'x')
            nb--;
        nb--;
    }
    return (nb);
}

static int conditions(int which, char *width_mod, char *flag)
{
    if (which == 1) {
        if ((width_mod[1] == '0') || (width_mod[1] == '2' &&
    (flag[0] == 'c' || flag[0] == 's' || flag[0] == 'S')))
            return (1);
        else
            return (0);
    }
    else {
        if (width_mod[1] == '2' && (flag[0] != 'c' && flag[0] != 's' &&
    flag[0] != 'S'))
            return (1);
        else
            return (0);
    }
    return (0);
}

void print_width(char *width_mod, int length, char *print, char *flag)
{
    int nb = my_getnbr(flag_to_number(flag)) - length;

    if (nb <= 0) {
        negative_width(width_mod, print, flag);
        return;
    }
    nb = positive_width(width_mod, print, flag, nb);
    if (conditions(1, width_mod, flag) == 1)
        for ( ; nb != 0; nb--)
            my_putchar(' ');
    if (conditions(2, width_mod, flag) == 1) {
        if (print[0] == '-')
            print = neg_int(print, &nb);
        for ( ; nb != 0; nb--)
            my_putchar('0');
    }
    my_putstr(print);
    if (width_mod[1] == '1')
        for ( ; nb != 0; nb--)
            my_putchar(' ');
}