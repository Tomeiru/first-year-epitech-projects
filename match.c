/*
** EPITECH PROJECT, 2020
** match
** File description:
** match
*/

#include "proto.h"

int match(char const *s1, char const *s2)
{
    int i = 0;
    int star_count = 0;

    for (i = 0; s2[i]; i++)
        if (s2[i] == '*')
            star_count++;
    if (star_count == 0)
        return (no_star(s1, s2));
    if (star_count == 1)
        return (one_star(s1, s2));
    if (star_count > 1)
        return(stars(s1, s2));
}