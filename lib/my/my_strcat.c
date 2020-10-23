/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest , char const *src)
{
    int i = 0;
    int k = 0;

    while (dest[i] != '\0')
        i++;
    while (src[k] != '\0') {
        dest[i + k] = src[k];
        k++;
    }
    dest[i + k] = '\0';
    return (dest);
}