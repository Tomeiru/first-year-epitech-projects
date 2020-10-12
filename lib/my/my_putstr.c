/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int l = 0;

    while (str[l] != '\0') {
        my_putchar(str[l]);
        l += 1;
    }
    return (0);
}
