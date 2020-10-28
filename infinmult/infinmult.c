/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** infinadd
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

char *infinmult(char *fst_num, char *sec_num)
{
    int fst_sign = my_sign(fst_num);
    int sec_sign = my_sign(sec_num);
    int fst_length = my_strlen(fst_num);
    int sec_length = my_strlen(sec_num);
    char *fst_abs = absol(fst_num, fst_sign, fst_length);
    char *sec_abs = absol(sec_num, sec_sign, sec_length);
    char *result;

    if (my_strlen(fst_abs) >= my_strlen(sec_abs))
        result = calcmult(fst_abs, sec_abs);
    else 
        result = calcmult(sec_abs, fst_abs);
    if ((fst_sign + sec_sign == 0) && result[0] != '0')
        result = minus_adder(result);
    return (result);
}