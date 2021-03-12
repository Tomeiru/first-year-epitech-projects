/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

#include "matchstick.h"

int my_getnbr(char const *str)
{
    int i = 0;
    long number = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10;
            number = number + str[i] - '0';
        }
    }
    if (number > 2147483647)
        return (-1);
    return ((int)number);
}