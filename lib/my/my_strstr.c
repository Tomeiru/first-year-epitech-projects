/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** returns pointer to beginning of substring if found, null if not
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    int x = 0;

    for( ; str[i] != '\0'; i++) {
        if (str[i] == to_find[0]) {
            x = i;
            j++;
        }
        else if (str[i] == to_find[j] && to_find[j] != '\0')
            j++;
    }
    if (to_find[j] == '\0')
        return (&str[x]);
    return (0);
}
