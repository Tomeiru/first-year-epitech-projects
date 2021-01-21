/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** returns 1 if string is empty or contains only uppercase letters, else 0
*/

#include "my.h"

int my_str_isupper(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0'; i++)
        if (str[i] < 65 || str[i] > 90)
            return (0);
    return (1);
}
