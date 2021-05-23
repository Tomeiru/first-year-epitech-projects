/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** lib_fct
*/

#include "corewar.h"

int my_str_isnum(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}

int my_str_ishexa(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0'; i++)
        if ((str[i] < '0' || str[i] > '9') &&
        (str[i] < 'A' || str[i] > 'F'))
            return (0);
    return (1);
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

int my_strlen(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0'; i++);
    return (i);
}