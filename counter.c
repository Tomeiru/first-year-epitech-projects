/*
** EPITECH PROJECT, 2020
** counter
** File description:
** counter
*/

#include "eval_expr.h"

int add_counter(char const *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '-' || str[i] == '+')
            count++;
    return (count);
}

int fac_counter(char const *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '%' || str[i] == '*' || str[i] == '/')
            count++;
    return (count);
}