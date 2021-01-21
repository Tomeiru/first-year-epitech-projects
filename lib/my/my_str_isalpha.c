/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** returns 1 if string is empty or contains only letters, else 0
*/

#include "my.h"

int my_str_isalpha(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0'; i++)
        if (str[i] < 32 || str[i] > 32 && str[i] < 65
        || str[i] > 90 && str[i] < 97 || str[i] > 122)
            return (0);
    return (1);
}