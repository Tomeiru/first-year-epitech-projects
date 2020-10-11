/*
** EPITECH PROJECT, 2020
** one_star
** File description:
** one_star
*/

#include "proto.h"

int one_star(char const *s1, char const*s2)
{
    int i = 0;
    int in = 0;
    int inc = 0;
    int p = 0;

    for (i = 0; s2[i] != '*' && s1[i] == s2[i]; i++);
    if (s2[i + 1] == '\0')
        return (1);
    if (s2[i + 2] == '\0' && s2[i + 1] == s1[my_strlen(s1) - 1])
        return (1);
    for (in = 0; s1[i + in] != s2[i + 1] && s1[i + in] != '\0'; in++);
        if (s1[i + in] == '\0')
            return (0);
    for (inc = 0; s1 [i + in + inc] == s2[i + 1 + inc] && s1[i + in + inc] != '\0'; inc++);
        if (s1[i + in + inc] == '\0' && s2[i + 1 + inc] == '\0')
            return (1);
        else {
            return (0);
        }
}