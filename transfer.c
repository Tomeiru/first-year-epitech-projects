/*
** EPITECH PROJECT, 2021
** B-MAT-200-STG-2-1-107transfer-alessandro.tosi
** File description:
** transfer
*/

#include "transfer.h"

double get_double_from_char(char *str, double x)
{
    int nb_star = 0;
    double value = 0;
    double y = 0;
    double z = 0;
    char *endptr;

    for (int i = 0; str[i]; i++)
        if (str[i] == '*')
            nb_star++;
    if (nb_star == 0)
        return ((double)atoi(str));
    value = (double)strtol(str, &endptr, 10);
    endptr++;
    for (int i = 1; i <= nb_star; i++) {
        y = (double)strtol(endptr, &endptr, 10);
        z = pow(x, (double)i);
        value += (y * z);
        endptr++;
    }return (value);
}

double single_op(char *as, char *bs, double x)
{
    double a = get_double_from_char(as, x);
    double b = get_double_from_char(bs, x);
    if (b == 0)
        exit(84);
    return (a/b);
}

double multi_op(int ac, char **av, double x)
{
    double value = 0;

    for (int i = 1; i != ac; i += 2) {
        if (i == 1)
            value = single_op(av[i], av[i + 1], x);
            else
            value *= single_op(av[i], av[i + 1], x);
    }return (value);
}

double get_value(int ac, char **av, double x)
{
    if (ac == 3)
        return (single_op(av[1], av[2], x));
    else
        return (multi_op(ac, av, x));
}

int transfer(int ac, char **av)
{
    double i_divided = 0;

    for (int i = 0; i < 1001; i++) {
        i_divided = (double)i / (double)1000;
        printf("%.3f -> %.5f\n", i_divided, get_value(ac, av, i_divided));
    }return (0);
}