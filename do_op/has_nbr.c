/*
** EPITECH PROJECT, 2020
** has_nbr
** File description:
** has_nbr
*/

#include "doop.h"

int has_nbr(char *c)
{
    int i = 0;
    int count = 0;

    for (i = 0; c[i]; i++)
        if (c[i] >= '0' && c[i] <= '9')
            count++;
    return (count);
}