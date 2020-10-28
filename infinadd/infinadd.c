/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** infinadd
*/

#include "infinadd.h"
#include "my.h"

char *infinadd(char *fst_num, char *sec_num)
{
    int fst_sign = my_sign(fst_num);
    int sec_sign = my_sign(sec_num);
    int fst_length = my_strlen(fst_num);
    int sec_length = my_strlen(sec_num);
    char *fst_abs = absol(fst_num, fst_sign, fst_length);
    char *sec_abs = absol(sec_num, sec_sign, sec_length);
    int longest = longest_string(fst_length, sec_length, fst_sign, sec_sign);
    int i = 0;
    int j = 0;

    for (i = 0; sec_abs[i] == '0'; i++);
    for (j = 0; fst_abs[j] == '0'; j++);
    if (i == my_strlen(sec_abs) && j == my_strlen(fst_abs))
        return ("0");
    if (longest == 0)
        return (same_tenth(fst_abs, sec_abs, fst_sign, sec_sign));
    if (longest == 1)
        return (first_longest(fst_abs, sec_abs, fst_sign, sec_sign));
    if (longest == -1)
        return (second_longest(fst_abs, sec_abs, fst_sign, sec_sign));
}