/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** same_tenth
*/

#include "infinadd.h"
#include "my.h"

static char *minus_adder(char *str)
{
    int i = 0;

    str = my_revstr(my_strdup(str));
    for (i = 0; str[i] != '\0'; i++);
    str[i] = '-';
    str = my_revstr(my_strdup(str));
    return (str);
}

int biggest_number(char *fst_num, char *sec_num, int fst_sign, int sec_sign)
{
    for (int i = 0; fst_num[i]; i++) {
        if (fst_num[i] > sec_num[i] && fst_sign == -1)
            return (2);
        if (fst_num[i] < sec_num[i] && sec_sign == -1)
            return (-2);
        if (fst_num[i] > sec_num[i] && fst_sign == 1)
            return (1);
        if (fst_num[i] < sec_num[i] && sec_sign == 1)
            return (-1);
        if (fst_sign == 1 && sec_sign == 1)
            return (0);
    }
    if (fst_sign + sec_sign == 0)
        return (-9);
    return (0);
}

char *same_tenth(char *fst_num, char *sec_num, int fst_sign, int sec_sign)
{
    int biggest = biggest_number(fst_num, sec_num, fst_sign, sec_sign);

    fst_num = my_revstr(my_strdup(fst_num));
    sec_num = my_revstr(my_strdup(sec_num));
    if (fst_sign + sec_sign == 0) {
        if (biggest >= 0 && biggest != 2)
            return (stenth_dsign(fst_num, sec_num, 0, 0));
        if (biggest == -1)
            return (stenth_dsign(sec_num, fst_num, 0, 0));
        if (biggest == 2)
            return (minus_adder(stenth_dsign(fst_num, sec_num, 0, 0)));
        if (biggest == -2)
            return (minus_adder(stenth_dsign(sec_num, fst_num, 0, 0)));
        if (biggest == -9)
            return ("0");
    }
    if (fst_sign + sec_sign == -2)
        return (minus_adder(stenth_ssign(fst_num, sec_num, 0, 0)));
    if (fst_sign + sec_sign == 2)
        return (stenth_ssign(fst_num, sec_num, 0, 0));
    return (0);
}