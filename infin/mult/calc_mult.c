/*
** EPITECH PROJECT, 2020
** Bistromatic
** File description:
** calc
*/

#include "../../include/bistromatic.h"
#include "../../include/my.h"

char *mult_line(char *fst_abs, int num_line, int value)
{
    int fst_length = my_strlen(fst_abs);
    char *line = malloc(sizeof(char) * (fst_length + num_line + 2));
    int i = num_line;
    int number = 0;
    int retenue = 0;
    int p = 0;

    for (int m = 0; num_line != m; m++)
        line[m] = '0';
    for (fst_length; fst_length != 0; fst_length--) {
        int a = (fst_abs[p++] - 48);
        number = (a * value + retenue);
        line[i++] = number % 10 + 48;
        retenue = number / 10;
    }
    if (retenue > 0)
        line[i] = (retenue + 48);
    line[++i] = '\0';
    return (line);
}

char *calc_mult(char *fst_abs, char *sec_abs)
{
    int sec_length = my_strlen(sec_abs);
    char **result = malloc(sizeof(char *) * sec_length);
    int j = 0;
    char *ans = "0";

    fst_abs = my_revstr(my_strdup(fst_abs));
    sec_abs = my_revstr(my_strdup(sec_abs));
    for ( ; sec_length != 0; sec_length--) {
        int b = (sec_abs[j] - 48);
        result[j] = my_revstr(my_strdup(mult_line(fst_abs, j, b)));
        ans = infin_add(ans, result[j]);
        j++;
    }
    return (ans);
}