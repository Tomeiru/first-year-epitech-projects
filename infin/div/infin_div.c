/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** infinadd
*/

#include "../../include/bistromatic.h"
#include "../../include/my.h"

char *infin_div(char *fst_num, char *sec_num)
{
    int fst_sign = my_sign(fst_num);
    int sec_sign = my_sign(sec_num);
    int fst_length = my_strlen(fst_num);
    int sec_length = my_strlen(sec_num);
    char *fst_abs = absol(fst_num, fst_sign, fst_length);
    char *sec_abs = absol(sec_num, sec_sign, sec_length);
    char *result;

    if (do_we_div(fst_abs, sec_abs) != 2) {
        if (do_we_div(fst_abs, sec_abs) == 1)
            result = "1";
        if (do_we_div(fst_abs, sec_abs) == 0)
            result = "0";
    }
    else
        result = div_glob(fst_abs, sec_abs);
    if ((fst_sign + sec_sign == 0) && result[0] != '0')
        result = minus_adder(result);
    return (result);
}