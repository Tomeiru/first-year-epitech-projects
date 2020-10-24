/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp
*/

#include <unistd.h>
#include "rush.h"

int sqcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    if (s1[i] != '\0' || s2[i] != '\0')
        return (0);
    else
        return (1);
}
