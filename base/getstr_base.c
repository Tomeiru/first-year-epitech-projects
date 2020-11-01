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
    int i = 0;

    for (; base[i] != nbr[0]; i++);
    my_strdup(res);
    res = infin_mult(nbrtostr(i), infinpower(nbrtostr(len_base), len - 1));
    len--;
    nbr++;
    if (len > 0)
        res = infin_add(res, getstr_base(nbr, base, len, res));
    return (res);
}

int condition (char c, char *op)
{
    if (c != op[0] && c != op[1] && c != op[2] && c !=
        op[3] && c != op[4] && c != op[5] && c != op[6])
        return (1);
    return (0);
}

int condition2 (char c, char *op)
{
    if (c == op[0] || c == op[1] || c == op[2] || c ==
        op[3] || c == op[4] || c == op[5] || c == op[6])
        return (1);
    return (0);
}

char *getstr(char *base, char *op, char *nbr)
{
    char *temp = malloc(10000);
    char *result = malloc(10000);
    int k = 0;
    int g = 0;

    if (condition2(nbr[0], op))
        result[g++] = nbr++;
    for (; nbr[0] == base[0]; nbr++);
    for (int i = 0; nbr[i] != '\0'; i++) {
        if (condition(nbr[i], op) == 1)
            temp[k++] = nbr[i];
        if (condition2(nbr[i], op) == 1 || nbr[i + 1] == '\0') {
            temp[k] = '\0';
            if (my_strlen(temp) > 0)
                temp = getstr_base(temp, base, my_strlen(temp), "0");
            for (int j = 0; temp[j] != '\0'; j++)
                result[g++] = temp[j];
            if (condition2(nbr[i], op) == 1)
                result[g] = nbr[i];
            g++;
            k = 0;
        }
    }
    result[g] = '\0';
    if (my_strlen(result) > 0)
        return (result);
    return ("0");
}