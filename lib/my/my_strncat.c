/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** my_strncat
*/

#include "my.h"

char *my_strncat(char *dest , char  const *src, int nb)
{
    int i = 0;
    int p = 0;

    while (dest[i] != '\0')
        i++;
    while (src[p] != '\0' && p < nb) {
        dest[i + p] = src[p];
        p++;
    }
    dest[i + p] = '\0';
    return (dest);
}