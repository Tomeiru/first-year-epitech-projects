/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** stenth_ssign
*/

#include "infinadd.h"
#include "my.h"

char *stenth_ssign(char *fst_num, char *sec_num, int retenue, int number)
{
    char *result = malloc(sizeof(char) * my_strlen(fst_num) + 1);
    int i = 0;

    for (i = 0; fst_num[i]; ++i) {
        int a = (fst_num[i] - 48);
        int b = (sec_num[i] - 48);
        number = a - b + retenue;
        if (number >= 10) {
            retenue = 1;
            number %= 10;
        }
        else
            retenue = 0;
        result[i] = number + 48;
    }
    retenue == 1 ? result[i] = '1' : i;
    retenue == 1 ? result[i + 1] = '\0' : i;
    retenue == 0 ? result[i] = '\0' : i;
    result = my_revstr(my_strdup(result));
    for (i = 0; result[0] == '0'; ++result);
    return (result);
}