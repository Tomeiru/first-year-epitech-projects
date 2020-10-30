/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** infinadd
*/

#include "../../include/bistromatic.h"
#include "../../include/my.h"

void div_by_zero(char *num)
{
    for (; num[0] == '0'; ++num);
    if (num[0] == '\0') {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_USAGE);
    }
}

int do_we_mod(char *fst_num, char *sec_num)
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

char *infin_mod(char *fst_num, char *sec_num)
{
    int fst_sign = my_sign(fst_num);
    int sec_sign = my_sign(sec_num);
    int fst_length = my_strlen(fst_num);
    int sec_length = my_strlen(sec_num);
    char *fst_abs = absol(fst_num, fst_sign, fst_length);
    char *sec_abs = absol(sec_num, sec_sign, sec_length);
    char *result;

    div_by_zero(sec_abs);
    if (do_we_mod(fst_abs, sec_abs) != 2) {
        if (do_we_mod(fst_abs, sec_abs) == 1)
            result = "0";
        if (do_we_mod(fst_abs, sec_abs) == 0)
            return (my_strdup(fst_abs));
    }
    else
        result = mod_glob(fst_abs, sec_abs);
    if ((fst_sign + sec_sign == 0) && result[0] != '0')
        result = minus_adder(result);
    return (result);
}