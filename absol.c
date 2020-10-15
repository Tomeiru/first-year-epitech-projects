/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** absol
*/

#include "infinadd.h"
#include "my.h"

char *absol(char *num, int sign, int length)
{
    if (sign == -1) {
        num = my_revstr(my_strdup(num));
        num[length - 1] = '\0';
        num = my_revstr(my_strdup(num));
        return (num);
    }
    else
        return (num);
}