/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** lib_fct
*/

#include "corewar.h"

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}

int my_strlen(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0'; i++);
    return (i);
}