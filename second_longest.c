/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-infinadd-mathieu.brujan
** File description:
** second_longest
*/

#include "infinadd.h"
#include "my.h"

void second_longest(char *fst_num, char *sec_num, int fst_sign, int sec_sign)
{
    int fst_len = my_strlen(fst_num);
    int sec_len = my_strlen(sec_num);
    int dif_len = sec_len - fst_len;

    fst_num = my_revstr(my_strdup(fst_num));
    fst_num = zero(fst_num, dif_len, fst_len);
    fst_num = my_revstr(my_strdup(fst_num));
    same_tenth(fst_num, sec_num, fst_sign, sec_sign);
}