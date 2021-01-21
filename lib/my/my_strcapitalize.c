/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** capitalizes the beginning of every word
*/

#include "my.h"

int check_pre_false(char *str, int i)
{
    if (str[i - 1] != ' ' || str [i - 1] != '-'|| str [i - 1] != '+')
        return (1);
    return (0);
}

int check_pre_true(char *str, int i)
{
    if (str[i - 1] == ' ' || str [i - 1] == '-'|| str [i - 1] == '+')
        return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
        i++;
    }
    for ( ; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122 && check_pre_true(str, i) == 1)
            str[i] = str[i] - 32;
        else if ((str[i] >= 65 && str[i] <= 90) && check_pre_false(str, i) == 1)
            str[i] = str[i] + 32;
    }
    return (str);
}