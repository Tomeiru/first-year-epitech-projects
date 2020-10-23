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
    int k = 0;

    while (dest[i] != '\0')
        i++;
    while (src[k] != '\0' && k < nb) {
        dest[i + k] = src[k];
        k++;
    }
    dest[i + k] = '\0';
    return (dest);
}