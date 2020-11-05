/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int ans = 0;

    if (n == 0)
        return (0);
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] == s2[i] || n < i)
            i++;
        else {
            ans = s1[i] - s2[i];
            return (ans);
        }
    }
    return (0);
}
