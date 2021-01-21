/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** returns 1 if string is empty or contains only printable characters, else 0
*/

#include "my.h"

int my_str_isprintable(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0'; i++)
        if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
            return (0);
    return (1);
}