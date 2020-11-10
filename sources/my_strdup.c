/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** my_strdup
*/

#include "my_printf.h"

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}