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

    for (i = 0; i != len; i++)
        newstr[i] = str[i];
    for ( ; i != len + dif; i ++)
        newstr[i] = '0';
    newstr[i] = '\0';
    return (newstr);
}