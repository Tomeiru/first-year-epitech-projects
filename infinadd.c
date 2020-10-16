/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** infinadd
*/

#include "infinadd.h"
#include "my.h"

int infinadd(char *fst_num, char *sec_num)
{
    int fst_sign = my_sign(fst_num);
    int sec_sign = my_sign(sec_num);
    int fst_length = my_strlen(fst_num);
    int sec_length = my_strlen(sec_num);
    char *fst_abs = absol(fst_num, fst_sign, fst_length);
    char *sec_abs = absol(sec_num, sec_sign, sec_length);
    int longest = longest_string(fst_length, sec_length, fst_sign, sec_sign);

    if (longest == 0)
        same_tenth(fst_abs, sec_abs, fst_sign, sec_sign);
    return(0);
}