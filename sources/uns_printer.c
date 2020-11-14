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
    char *width_modifier = width_check(flag);
    int length = my_strlen(nb);

    print_width(width_modifier, length, nb, flag);
}

void huns(unsigned long long number, char *flag)
{
    unsigned short cast = number;
    char *nb = print_u(cast);
    char *width_modifier = width_check(flag);
    int length = my_strlen(nb);

    print_width(width_modifier, length, nb, flag);
}

void hhuns(unsigned long long number, char *flag)
{
    unsigned char cast = number;
    char *nb = print_u(cast);
    char *width_modifier = width_check(flag);
    int length = my_strlen(nb);

    print_width(width_modifier, length, nb, flag);
}

void lluns(unsigned long long number, char *flag)
{
    char *nb = print_u(number);
    char *width_modifier = width_check(flag);
    int length = my_strlen(nb);

    print_width(width_modifier, length, nb, flag);
}