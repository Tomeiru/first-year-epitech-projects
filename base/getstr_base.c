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
    res = infin_mult(my_nbrtostr(i), infinpower(my_nbrtostr(len_base), len - 1));
    len--;
    nbr++;
    if (len > 0)
        res = infin_add(res, getstr_base(nbr, base, len, res));
    printf("%s\n", res);
    return (res);
}

int main (int ac, char **av)
{
    getstr_base(av[1], av[2], my_strlen(av[1]), "0");
    return (0);
}