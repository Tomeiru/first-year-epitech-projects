/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** infinadd
*/

#include "../../include/bistromatic.h"
#include "../../include/my.h"

char *infin_mult(char *fst_num, char *sec_num)
{
    int fst_sign = my_sign(fst_num);
    int sec_sign = my_sign(sec_num);
    int fst_length = my_strlen(fst_num);
    int sec_length = my_strlen(sec_num);
    char *fst_abs = absol(fst_num, fst_sign, fst_length);
    char *sec_abs = absol(sec_num, sec_sign, sec_length);
    char *result;

    if (my_strlen(fst_abs) >= my_strlen(sec_abs))
        result = calc_mult(fst_abs, sec_abs);
    else 
        result = calc_mult(sec_abs, fst_abs);
    if ((fst_sign + sec_sign == 0) && result[0] != '0')
        result = minus_adder(result);
    return (result);
}