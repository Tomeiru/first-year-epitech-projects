/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int result = 0;
    int i = 0;
    int sign = 1;

    if (str[i] == '-') {
            sign *= -1;
            i = 1;
    }
    for ( ; str[i] != '\0'; i++) {
        result *= 10;
        result += str[i] - 48;
    }
    result *= sign;
    return (result);
}