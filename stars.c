/*
** EPITECH PROJECT, 2020
** stars
** File description:
** stars
*/

#include "proto.h"

int stars (char const *s1, char const *s2)
{
    int i = 0;
    int star_count = 0;
    int in = 0;
    int inc = 0;

    for (i = 0; s2[i]; i++)
        if (s2[i] == '*')
            star_count++;
    if (star_count == 1)
        return (one_star(s1, s2));
    for (in = 0; s2[in] != '*'; in++);
    inc = in + 1;
    for (inc = 0; s2[inc] != '*'; inc++);
    for (in; in == inc; in++)

    return (0);
}