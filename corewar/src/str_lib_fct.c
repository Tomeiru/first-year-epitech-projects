/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** lib_fct
*/

#include "../include/corewar.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
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