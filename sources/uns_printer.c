/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** int_printer
*/

#include "my_printf.h"

void nuns(unsigned long long number, char *flag)
{
    unsigned int cast = number;
    char *nb = print_u(cast);

    my_putstr(nb);
}

void huns(unsigned long long number, char *flag)
{
    unsigned short cast = number;
    char *nb = print_u(cast);

    my_putstr(nb);
}

void hhuns(unsigned long long number, char *flag)
{
    unsigned char cast = number;
    char *nb = print_u(cast);

    my_putstr(nb);
}

void lluns(unsigned long long number, char *flag)
{
    char *nb = print_u(number);

    my_putstr(nb);
}