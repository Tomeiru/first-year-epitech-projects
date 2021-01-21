/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** returns 1 if string is empty or contains only lowercase letters, else 0
*/

#include "my.h"

int my_str_islower(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0'; i++)
        if (str[i] < 97 || str[i] > 122)
            return (0);
    return (1);
}
