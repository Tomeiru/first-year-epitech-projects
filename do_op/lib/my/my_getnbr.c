/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr (char const *str)
{
    int i = 0;
    int sign = 1;
    long number = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '-')
            sign = sign * -1;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10;
            number = number + str[i] - '0';
        }
        if (str[i] != '-' && str[i] != '+' && str[i] > 57)
            break;
    }
    number = number * sign;
    if (number > 2147483647 || number < -2147483647)
        return (0);
    return((int)number);
}