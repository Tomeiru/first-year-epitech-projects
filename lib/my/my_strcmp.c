/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** outputs difference between lengths of strings submitted
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int reference = my_strlen(s1);
    int count = 0;

    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] == s2[i])
            count++;
    return (reference - count);
}
