/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** first_longest
*/

#include "infinadd.h"
#include "my.h"

void first_longest(char *fst_num, char *sec_num, int fst_sign, int sec_sign)
{
    int fst_len = my_strlen(fst_num);
    int sec_len = my_strlen(sec_num);
    int dif_len = fst_len - sec_len;

    sec_num = my_revstr(my_strdup(sec_num));
    sec_num = zero(sec_num, dif_len, sec_len);
    sec_num = my_revstr(my_strdup(sec_num));
    same_tenth(fst_num, sec_num, fst_sign, sec_sign);
}