/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** int_printer
*/

#include "my_printf.h"

void nbin(unsigned long long number, char *flag)
{
    unsigned int cast = number;
    char *nb = print_b(cast);

    my_putstr(nb);
}

void hbin(unsigned long long number, char *flag)
{
    unsigned short cast = number;
    char *nb = print_b(cast);

    my_putstr(nb);
}

void hhbin(unsigned long long number, char *flag)
{
    unsigned char cast = number;
    char *nb = print_b(cast);

    my_putstr(nb);
}

void llbin(unsigned long long number, char *flag)
{
    char *nb = print_b(number);

    my_putstr(nb);
}