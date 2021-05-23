/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** lib_fct
*/

#include "corewar.h"

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

void my_putnbr(int nb)
{
    int div = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    for ( ; (nb/div) >= 10; div *= 10);
    for ( ; div > 0; div /= 10)
        my_putchar((nb/div) % 10 + 48);
}