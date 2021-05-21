/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** my_getnbr
*/

#include "asm.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    int number = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '-')
            sign = sign * -1;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10;
            number = number + str[i] - '0';
        }
    }
    number = number * sign;
    return (number);
}