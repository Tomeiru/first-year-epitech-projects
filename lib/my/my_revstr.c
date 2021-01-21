/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** returns reversed string
*/

#include "my.h"

char *my_revstr(char *str)
{
    char temp;
    int j = my_strlen (str) - 1;
    int i = 0;

    for ( ; i <= j; i ++){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    return (str);
}