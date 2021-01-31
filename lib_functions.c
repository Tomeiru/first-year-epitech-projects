/*
** EPITECH PROJECT, 2021
** B-PSU-101-STG-1-1-minishell1-mathieu.brujan
** File description:
** lib_functions
*/

#include "mysh.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
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

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    long number = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '-')
            sign = sign * -1;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10;
            number = number + str[i] - '0';
        }
    }
    number = number * sign;
    if (number > 2147483647 || number < -2147483647)
        return (0);
    return ((int)number);
}

int is_number(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < '0' || str[i] > '9')
            return (0);
    return (1);
}

int is_alphanum(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!((str[i] >= '0' && str[i] <= '9') ||
        (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
            return (0);
    return (1);
}