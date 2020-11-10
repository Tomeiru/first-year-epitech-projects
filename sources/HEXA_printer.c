/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** int_printer
*/

#include "my_printf.h"

void nHEXA(unsigned long long number, char *flag)
{
    unsigned int cast = number;
    char *nb = print_X(cast);

    my_putstr(nb);
}

void hHEXA(unsigned long long number, char *flag)
{
    unsigned short cast = number;
    char *nb = print_X(cast);

    my_putstr(nb);
}

void hhHEXA(unsigned long long number, char *flag)
{
    unsigned char cast = number;
    char *nb = print_X(cast);

    my_putstr(nb);
}

void llHEXA(unsigned long long number, char *flag)
{
    char *nb = print_X(number);

    my_putstr(nb);
}