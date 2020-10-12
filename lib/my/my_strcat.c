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
    int p = 0;

    while (dest[i] != '\0') 
        i++;
    while (src[p] != '\0') {
        dest[i + p] = src[p];
        p++;
    }
    dest[i + p] = '\0';
    return (dest);
}