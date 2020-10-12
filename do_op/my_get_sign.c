/*
** EPITECH PROJECT, 2020
** my_get_sign
** File description:
** my_get_sign
*/

#include "doop.h"

int my_get_sign(char *c)
{
    int i = 0;

    for (i = 0; c[i]; i++) {
        if (c[i] == '+')
            return (0);
        if (c[i] == '-')
            return (1);
        if (c[i] == '*')
            return (2);
        if (c[i] == '/')
            return (3);
        if (c[i] == '%')
            return (4);
    }
}