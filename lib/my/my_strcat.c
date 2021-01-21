/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** concatenates two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *dest_pointer = dest;

    if (dest[0] == '\0' && src[0] == '\0')
        return (0);
    for ( ; dest_pointer[i] != '\0'; i++);
    for ( ; src[j] != '\0'; i++) {
        dest_pointer[i] = src[j];
        j++;
    }
    dest_pointer[i] = '\0';
    return (dest);
}