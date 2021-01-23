/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp
*/

#include "giantman.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int ans = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] == s2[i])
            i++;
        else {
            ans = s1[i] - s2[i];
            return (ans);
        }
    }
    return (0);
}

char *my_revstr(char *str)
{
    char temp;
    int j = my_strlen (str) - 1;
    int i = 0;

    for ( ; i <= j; i ++){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    return (str);
}

char *my_strdup(char const *src)
{
    char *dest;
    int i = 0;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    for (i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i]) {
        i = i + 1;
    }
    return (i);
}