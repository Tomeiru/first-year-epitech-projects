/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** longest_string
*/

#include "infinadd.h"
#include "my.h"

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