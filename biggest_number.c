/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** biggest_number
*/

#include "infinadd.h"
#include "my.h"

int biggest_number (char *fst_num, char *sec_num, int fst_sign, int sec_sign)
{
    for (int i = 0; fst_num[i]; i++) {
        if (fst_num[i] > sec_num[i] && fst_sign == -1) {
            my_putchar('-');
            return (1);
        }
        if (fst_num[i] < sec_num [i] && sec_sign == -1) {
            my_putchar('-');
            return (-1);
        }
        if (fst_num[i] > sec_num[i] && fst_sign == 1)
            return (1);
        if (fst_num[i] < sec_num [i] && sec_sign == 1)
            return (-1);
    }
    my_putchar('0');
    return (0);
}