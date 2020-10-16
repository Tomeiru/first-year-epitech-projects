/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-infinadd-mathieu.brujan
** File description:
** zero
*/

#include "infinadd.h"
#include "my.h"

char *zero(char *str, int dif, int len)
{
    int i = 0;
    char *newstr = malloc(sizeof(char) * dif + len + 1);

    for (i = 0; i != dif + len; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            newstr[i] = str[i];
        else
            newstr[i] = '0';
    }
    newstr[i] = '\0';
    return (newstr);
}