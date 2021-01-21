/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** puts all letters contained in a string in uppercase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
        else
            str[i] = str[i];
    }
    return (str);
}
