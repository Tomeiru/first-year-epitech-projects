/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** first_longest
*/

#include "infinadd.h"
#include "my.h"

char *first_longest(char *fst_num, char *sec_num, int fst_sign, int sec_sign)
{
    int fst_len = my_strlen(fst_num);
    int sec_len = my_strlen(sec_num);
    int dif_len = fst_len - sec_len;
    char *result;

    sec_num = my_revstr(my_strdup(sec_num));
    sec_num = zero(sec_num, dif_len, sec_len);
    sec_num = my_revstr(my_strdup(sec_num));
    result = same_tenth(fst_num, sec_num, fst_sign, sec_sign);
    return (result);
}

char *second_longest(char *fst_num, char *sec_num, int fst_sign, int sec_sign)
{
    int fst_len = my_strlen(fst_num);
    int sec_len = my_strlen(sec_num);
    int dif_len = sec_len - fst_len;
    char *result;

    fst_num = my_revstr(my_strdup(fst_num));
    fst_num = zero(fst_num, dif_len, fst_len);
    fst_num = my_revstr(my_strdup(fst_num));
    result = same_tenth(fst_num, sec_num, fst_sign, sec_sign);
    return (result);
}