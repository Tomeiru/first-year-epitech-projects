/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** stenth_dsign
*/

#include "../../include/bistromatic.h"
#include "../../include/my.h"

char *stenth_dsign(char *fst_num, char *sec_num, int leftover, int number)
{
    char *result = malloc(sizeof(char) * my_strlen(fst_num) + 2);
    int i = 0;

    for (i = 0; fst_num[i]; ++i) {
        int a = (fst_num[i] - 48);
        int b = (sec_num[i] - 48);
        a - (b + leftover) < 0 ? a += 10 : a;
        number = a - (b + leftover);
        if (a >= 10)
            leftover = 1;
        else
            leftover = 0;
        result[i] = number + 48;
        number = a - (b + leftover);
    }
    result[i] = '\0';
    result = my_revstr(my_strdup(result));
    for (i = 0; result[0] == '0'; ++result);
    return (result);
}

char *stenth_ssign(char *fst_num, char *sec_num, int leftover, int number)
{
    char *result = malloc(sizeof(char) * my_strlen(fst_num) + 1);
    int i = 0;
    for (i = 0; fst_num[i]; ++i) {
        int a = (fst_num[i] - 48);
        int b = (sec_num[i] - 48);
        number = a + b + leftover;
        if (number >= 10) {
            leftover = 1;
            number %= 10;
        }
        else
            leftover = 0;
        result[i] = number + 48;
    }
    leftover == 1 ? result[i] = '1' : i;
    leftover == 1 ? result[i + 1] = '\0' : i;
    leftover == 0 ? result[i] = '\0' : i;
    result = my_revstr(my_strdup(result));
    for (i = 0; result[0] == '0'; ++result);
    return (result);
}