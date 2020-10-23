/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** my_strstr
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int m = 0;
    int k = 0;

    while (str[i] != '\0') {
        k = 0;
        for (m = 0; to_find[m] != '\0'; m++) {
            if (str[i + m] != to_find[m]) {
                k = 1;
                break;
            }
        }
        if (k != 1)
            return (&str[i]);
        i++;
    }
    return (0);
}