/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** 101pong
*/

#include "pong.h"

double *arg_to_vec(char **av, int nb_vec)
{
    double *res = malloc(sizeof(int) * 3);

    if (nb_vec == 1) {
        res[0] = atof(av[1]);
        res[1] = atof(av[2]);
        res[2] = atof(av[3]);
    }
    if (nb_vec == 2) {
        res[0] = atof(av[4]);
        res[1] = atof(av[5]);
        res[2] = atof(av[6]);
    }
    return (res);
}

int pong(int ac, char **av)
{
    double *vec_minus_one;
    double *vec_zero;
    int n;

    error(ac, av);
    vec_minus_one = arg_to_vec(av, 1);
    vec_zero = arg_to_vec(av, 2);
    n = atoi(av[7]);
    answer_calc(vec_minus_one, vec_zero, n);
    return (0);
}