/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** int_printer
*/

#include "my_printf.h"

void nint(long long number, char *flag)
{
    int cast = number;
    char *nb = print_di(cast);

    my_putstr(nb);
}

void hint(long long number, char *flag)
{
    short cast = number;
    char *nb = print_di(cast);

    my_putstr(nb);
}

void hhint(long long number, char *flag)
{
    char cast = number;
    char *nb = print_di(cast);

    my_putstr(nb);
}

void llint(long long number, char *flag)
{
    char *nb = print_di(number);

    my_putstr(nb);
}