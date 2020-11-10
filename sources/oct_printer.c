/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** int_printer
*/

#include "my_printf.h"

void noct(unsigned long long number, char *flag)
{
    unsigned int cast = number;
    char *nb = print_o(cast);

    my_putstr(nb);
}

void hoct(unsigned long long number, char *flag)
{
    unsigned short cast = number;
    char *nb = print_o(cast);

    my_putstr(nb);
}

void hhoct(unsigned long long number, char *flag)
{
    unsigned char cast = number;
    char *nb = print_o(cast);

    my_putstr(nb);
}

void lloct(unsigned long long number, char *flag)
{
    char *nb = print_o(number);

    my_putstr(nb);
}