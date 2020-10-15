/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** my_sign
*/

#include "infinadd.h"
#include "my.h"

int my_sign(char *num)
{
    if (num[0] == '-')
        return (-1);
    else
        return (1);
}