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
    int n = 0;
    int k = 0;

    while (str[i] != '\0') {
        k = 0;
        for (n = 0; to_find[n] != '\0'; n++) {
            if (str[i + n] != to_find[n]) {
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