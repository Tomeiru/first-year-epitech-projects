/*
** EPITECH PROJECT, 2020
** my_rev_str
** File description:
** my_rev_str
*/

#include "my.h"

void last_letter_swap(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}

char *my_revstr(char *str)
{
    int i = 0;
    int k = 0;
    int n = 0;

    while (str[i] != '\0')
        i++;
    i--;
    k = i;
    while (i != k / 2) {
        last_letter_swap(&str[n], &str[i]);
        n++;
        i--;
    }
    return (str);
}
