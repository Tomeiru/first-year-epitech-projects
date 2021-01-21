/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

#include "giantman.h"

int my_getnbr(char const *str)
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
    }
    number = number * sign;
    if (number > 2147483647 || number < -2147483647)
        return (0);
    return ((int)number);
}

char *my_get_first_line(char const *src)
{
    char *dest;
    int i = 0;

    for ( ; src[i] != '\n' && src[i] != '\0'; i++);
    dest = malloc(sizeof(char) * (i + 1));
    for (i = 0; src[i] != '\n'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

int my_put_nbr(int nb)
{
    int den = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    while ((nb/den) >= 10) {
        den*=10;
    }
    while (den > 0) {
        my_putchar((nb/den) % 10 + '0');
        den /= 10;
    }
    return (0);
}