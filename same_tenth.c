/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** same_tenth
*/

#include "infinadd.h"
#include "my.h"

int same_tenth(char *fst_num, char *sec_num, int fst_sign, int sec_sign)
{
    int biggest = biggest_number(fst_num, sec_num, fst_sign, sec_sign);

    fst_num = my_revstr(my_strdup(fst_num));
    sec_num = my_revstr(my_strdup(sec_num));
    if (fst_sign + sec_sign == 0) {
        if (biggest >= 0)
            my_putstr((stenth_dsign(fst_num, sec_num,
            0, 0)));
        if (biggest == -1)
            my_putstr((stenth_dsign(sec_num, fst_num,
            0, 0)));
        my_putchar('\n');
    }
    if (fst_sign + sec_sign == -2) {
        my_putchar('-');
        my_putstr(stenth_ssign(fst_num, sec_num, 0, 0));
        my_putchar('\n');
    }
    if (fst_sign + sec_sign == 2) {
        my_putstr(stenth_ssign(fst_num, sec_num, 0, 0));
        my_putchar('\n');
    }
}