/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** lib_fct
*/

#include "../include/corewar.h"

int my_str_isnum(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}

int my_str_ishexa(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0'; i++)
        if ((str[i] < '0' || str[i] > '9') &&
        (str[i] < 'A' || str[i] > 'F'))
            return (0);
    return (1);
}

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return (0);
    return (1);
}

int my_strlen(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0'; i++);
    return (i);
}

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