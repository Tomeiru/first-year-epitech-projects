/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-mathieu.brujan
** File description:
** getstr_base
*/

#include "../include/bistromatic.h"
#include "../include/my.h"

char *getstr_base(char *nbr, char *base, int len, char *res)
{
    int len_base = my_strlen(base);
    int i;

    if (nbr[0] == '-')
        my_putchar('-');
    for (i = 0; base[i] != nbr[0]; i++);
    res = infin_mult(nbrtostr(i), infinpower(nbrtostr(len_base), len - 1));
    len--;
    nbr++;
    if (len > 0)
        res = infin_add(res, getstr_base(nbr, base, len, res));
    return (res);
}

char *getstr(char *nbr, char *base, char *op)
{
    char *temp = malloc(10000);
    char *result = malloc(10000);
    int k = 0;
    int g = 0;

    for (int i = 0; nbr[i] != '\0'; i++)
    {
        if (nbr[i] != op[0] && nbr[i] != op[1] && nbr[i] != op[2] && nbr[i] !=
        op[3] && nbr[i] != op[4] && nbr[i] != op[5] && nbr[i] != op[6])
            temp[k++] = nbr[i];
        if (nbr[i] == op[0] || nbr[i] == op[1] || nbr[i] == op[2] || nbr[i] ==
        op[3] || nbr[i] == op[4] || nbr[i] == op[5] || nbr[i] == op[6] || nbr[i
        + 1] == '\0'){
            temp[k] = '\0';
            temp = getstr_base(temp, base, my_strlen(temp), "0");
            k = 0;
            for (int j = 0; temp[j] != '\0'; j++)
                result[g++] = temp[j];
            result[g++] = nbr[i];
        }
    }
    result[g - 1] = '\0';
    return (result);
}