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
    char *width_modifier = width_check(flag);
    int length = my_strlen(nb);

    print_width(width_modifier, length, nb, flag);
}

void hint(long long number, char *flag)
{
    short cast = number;
    char *nb = print_di(cast);
    char *width_modifier = width_check(flag);
    int length = my_strlen(nb);

    print_width(width_modifier, length, nb, flag);
}

void hhint(long long number, char *flag)
{
    char cast = number;
    char *nb = print_di(cast);
    char *width_modifier = width_check(flag);
    int length = my_strlen(nb);

    print_width(width_modifier, length, nb, flag);
}

void llint(long long number, char *flag)
{
    char *nb = print_di(number);
    char *width_modifier = width_check(flag);
    int length = my_strlen(nb);

    print_width(width_modifier, length, nb, flag);
}

void char_print(char number, char *flag)
{
    char nb[2];
    char *width_modifier = width_check(flag);

    nb[0] = number;
    nb[1] = '\0';
    print_width(width_modifier, 1, nb, flag);
}