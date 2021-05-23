/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** nbr_lib_fct
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