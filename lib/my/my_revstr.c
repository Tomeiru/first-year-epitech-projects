/*
** EPITECH PROJECT, 2020
** my_rev_str
** File description:
** my_rev_str
*/

#include "my.h"

void last_letter_swap(char *p, char *i)
{
    char z;

    z = *p;
    *p = *i;
    *i = z;
}

char *my_revstr(char *str)
{
    int i = 0;
    int m;
    int p = 0;

    while (str[i] != '\0')
        i++;
    i--;
    m = i;
    while (i != m / 2) {
        last_letter_swap(&str[p], &str[i]);
        p++;
        i--;
    }
    return (str);
}
