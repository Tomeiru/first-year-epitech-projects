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

char *zero(char *str, int dif, int len)
{
    int i = 0;
    char *newstr = malloc(sizeof(char) * dif + len + 1);

    for (i = 0; i != len; i++)
        newstr[i] = str[i];
    for ( ; i != len + dif; i++)
        newstr[i] = '0';
    newstr[i] = '\0';
    return (newstr);
}

int longest_string(int first, int second, int fst_sign, int sec_sign)
{
    if (fst_sign == -1)
        first -= 1;
    if (sec_sign == -1)
        second -= 1;
    if (first == second)
        return (0);
    if (first > second)
        return (1);
    if (first < second)
        return (-1);
    return (0);
}

int my_sign(char *num)
{
    if (num[0] == '-')
        return (-1);
    else
        return (1);
}
