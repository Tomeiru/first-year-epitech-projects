/*
** EPITECH PROJECT, 2020
** Bistromatic
** File description:
** infinsub
*/

#include "../../include/bistromatic.h"
#include "my.h"

char *infin_sub(char *fst_num, char *sec_num)
{
    int length = my_strlen(sec_num);

    if (sec_num[0] == '-') {
        sec_num = my_revstr(my_strdup(sec_num));
        sec_num[length - 1] = '\0';
        sec_num = my_revstr(my_strdup(sec_num));
    }
    else {
        sec_num = my_revstr(my_strdup(sec_num));
        sec_num[length] = '-';
        sec_num = my_revstr(my_strdup(sec_num));
    }
    return (infin_add(fst_num, sec_num));
}