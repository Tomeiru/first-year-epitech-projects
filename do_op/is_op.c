/*
** EPITECH PROJECT, 2020
** is_op
** File description:
** is_op
*/

#include "doop.h"

int is_op(char *c)
{
    int i = 0;
    int count = 0;

    for (i = 0; c[i]; i++) {
        if (c[i] == 42 || c[i] == '+' || c[i] == '-')
            count++;
        if (c[i] == '/' || c[i] == '%')
            count = 99;
    }
    return (count);
}