/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** stenth_dsign
*/

#include "infinadd.h"
#include "my.h"

char *stenth_dsign(char *fst_num, char *sec_num, int retenue, int number)
{
    char *result = malloc(sizeof(char) * my_strlen(fst_num) + 1);
    int i = 0;
    for (i = 0; fst_num[i]; ++i) {
        int a = (fst_num[i] - 48);
        int b = (sec_num[i] - 48);
        a - (b + retenue) < 0 ? a += 10 : a;
        number = a - (b + retenue);
        if (a >= 10)
            retenue = 1;
        else
            retenue = 0;
        result[i] = number + 48;
        number = a - (b + retenue);
    }
    result[i] = '\0';
    result = my_revstr(my_strdup(result));
    for (i = 0; result[0] == '0'; ++result);
    return (result);
}