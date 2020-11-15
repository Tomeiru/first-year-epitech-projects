/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** my_putchar
*/

#include "my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i = i + 1;
    }
    return (i);
}

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

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
}

char *my_revstr(char *str)
{
    char temp;
    int j = my_strlen(str) - 1;
    int i = 0;

    for ( ; i <= j; i++){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    return (str);
}