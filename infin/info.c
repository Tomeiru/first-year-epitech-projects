/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** absol
*/

#include "../include/bistromatic.h"
#include "../include/my.h"

char *minus_adder(char *str)
{
    int i = 0;

    str = my_revstr(my_strdup(str));
    for (i = 0; str[i] != '\0'; i++);
    str[i] = '-';
    str = my_revstr(my_strdup(str));
    return (str);
}

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

char *rest(char *total, char *abs, char quotient)
{
    char *nb = malloc(sizeof(char) * 2);
    char *rest;
    char *value;

    nb[0] = quotient;
    nb[1] = '\0';
    value = infin_mult(nb, abs);
    rest = infin_sub(total, value);
    return (rest);
}

int my_sign(char *num)
{
    if (num[0] == '-')
        return (-1);
    else
        return (1);
}
