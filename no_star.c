/*
** EPITECH PROJECT, 2020
** no_star
** File description:
** no_star
*/

#include "proto.h"

int no_star(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++);
    if (s1[i] == '\0')
        return (1);
    else
        return (0);
}