/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** puts all letters contained in a string in lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
        else
            str[i] = str[i];
    }
    return (str);
}
