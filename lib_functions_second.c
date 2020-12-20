/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "navy.h"

void my_put_nbr(int nb)
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
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int ans = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] == s2[i])
            i++;
        else {
            ans = s1[i] - s2[i];
            return (ans);
        }
    }
    return (0);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i = i + 1;
    }
    return (i);
}