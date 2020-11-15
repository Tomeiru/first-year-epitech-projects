/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** print_width
*/

#include "my_printf.h"

int flag_to_number(char *flag, char *width_mod)
{
    int i = 0;
    int result = 0;
    char *copy = my_strdup(flag);

    if (width_mod[3] == '1') {
        for ( ; copy[i] != '.'; i++);
        copy[i] = '\0';
    }
    for (i = 0; (copy[i] < '0' || copy[i] > '9') && copy[i] != '\0'; copy++);
    result = my_getnbr(copy);
    return (result);
}

void negative_width(char *width_mod, char *print, char *flag)
{
    if ((flag[0] == 'p' || flag[0] == 'i' || flag[0] == 'd') &&
    (width_mod[2] == '1' || width_mod[2] == '2')) {
        if (width_mod[2] == '1' && print[0] != '-')
            my_putchar('+');
        if (width_mod[2] == '2')
            my_putchar(' ');
    }
    if ((flag[0] == 'o' || flag[0] == 'x' || flag[0] == 'X' ||
    flag[0] == 'p') && (width_mod[0] == '1')) {
        my_putchar('0');
        if (flag[0] == 'x'|| flag[0] == 'p')
            my_putchar('x');
        if (flag[0] == 'X')
            my_putchar('X');
    }
}

int positive_width(char *width_mod, char *flag, int nb)
{
    if ((flag[0] == 'p' || flag[0] == 'i' || flag[0] == 'd') &&
    (width_mod[2] == '1' || width_mod[2] == '2'))
        nb--;
    if ((flag[0] == 'o' || flag[0] == 'x' || flag[0] == 'X' ||
    flag[0] == 'p') && (width_mod[0] == '1')) {
        if (flag[0] == 'X' || flag[0] == 'x' || flag[0] == 'p')
            nb--;
        nb--;
    }
    return (nb);
}

static int conditions(int which, char *width_mod, char *flag)
{
    flag = my_revstr(flag);
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

void print_width(char *width_mod, int len, char *print, char *flag)
{
    int nb = flag_to_number(flag, width_mod) - len_cho(len, width_mod, flag);

    if (nb <= 0) {
        negative_width(width_mod, print, my_revstr(flag));
        return (print_with_precision(width_mod, len, print, my_revstr(flag)));
    }
    nb = positive_width(width_mod, my_revstr(flag), nb);
    if (conditions(1, width_mod, flag) == 1)
        for ( ; nb != 0; nb--)
            my_putchar(' ');
    negative_width(width_mod, print, my_revstr(flag));
    if (conditions(2, width_mod, flag) == 1) {
        (print[0] == '-') ? print = neg_int(print, &nb) : 0;
        for ( ; nb != 0; nb--)
            my_putchar('0');
    }
    print_with_precision(width_mod, len, print, flag);
    if (width_mod[1] == '1')
        for ( ; nb != 0; nb--)
            my_putchar(' ');
}