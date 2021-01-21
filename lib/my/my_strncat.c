/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** concatenates n characters of src to the end of dest
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;
    char *dest_pointer = dest;

    if (dest[0] == '\0' && src[0] == '\0')
        return (0);
    for ( ; dest_pointer[i] != '\0'; i++);
    for ( ; src[j] != '\0' && nb != 0; i++) {
        dest_pointer[i] = src[j];
        j++;
        nb--;
    }
    dest_pointer[i] = '\0';
    return (dest);
}