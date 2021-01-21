/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** returns 1 if string is empty or contains only numbers, else 0
*/

#include "my.h"

int my_str_isnum(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0'; i++)
        if (str[i] < 48 || str[i] > 57)
            return (0);
    return (1);
}
