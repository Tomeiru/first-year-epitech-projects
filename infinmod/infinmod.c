/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** infinadd
*/

#include "infinadd.h"
#include "my.h"

static int do_we_mod(char *fst_num, char *sec_num)
{
    if (my_strlen(fst_num) < my_strlen(sec_num))
        return (0);
    if (my_strlen(fst_num) > my_strlen(sec_num))
        return (2);
    for (int i = 0; fst_num[i]; i++) {
        if (fst_num[i] > sec_num[i])
            return (2);
        if (fst_num[i] < sec_num[i])
            return (0);
    }
    return (1);
}

static char *minus_adder(char *str)
{
    int i = 0;

    str = my_revstr(my_strdup(str));
    for (i = 0; str[i] != '\0'; i++);
    str[i] = '-';
    str = my_revstr(my_strdup(str));
    return (str);
}

char *infinmod(char *fst_num, char *sec_num)
{
    int fst_sign = my_sign(fst_num);
    int sec_sign = my_sign(sec_num);
    int fst_length = my_strlen(fst_num);
    int sec_length = my_strlen(sec_num);
    char *fst_abs = absol(fst_num, fst_sign, fst_length);
    char *sec_abs = absol(sec_num, sec_sign, sec_length);
    char *result;

    if (do_we_mod(fst_abs, sec_abs) != 2) {
        if (do_we_mod(fst_abs, sec_abs) == 1)
            result = "0";
        if (do_we_mod(fst_abs, sec_abs) == 0)
            return (my_strdup(fst_abs));
    }
    else
        result = modglob(fst_abs, sec_abs);
    if ((fst_sign + sec_sign == 0) && result[0] != '0')
        result = minus_adder(result);
    return (result);
}