/*
** EPITECH PROJECT, 2021
** B-MAT-200-STG-2-1-106bombyx-alessandro.tosi
** File description:
** bombyx
*/

#include "bombyx.h"

void first_option(char **av)
{
    double value = atof(av[1]);
    double k = atof(av[2]);

    printf("%i %.2f\n", 1, value);
    for (int i = 2; i <= 100; i++) {
        value = k * value * ((1000 - value) / 1000);
        printf("%i %.2f\n", i, value);
    }
}

void second_option(char **av)
{
    double *value = malloc(sizeof(double) * 301);
    for (int i = 0; i <= 300; i++)
        value[i] = atof(av[1]);
    double i0 = atof(av[2]);
    double i1 = atof(av[3]);
    double k = 0;

    for (int i = 1; i <= 301; i++) {
        for (int j = 2; j < i0; j++)
            value[i] = (1 + k / 100) * value[i] * ((1000 - value[i]) / 1000);
        for (int j = i0; j <= i1; j++) {
            value[i] = (1 + k / 100) * value[i] * ((1000 - value[i]) / 1000);
            printf("%.2f %.2f\n", (1 + k / 100), value[i]);
        }k += 1;
    }
}

int bombyx(int ac, char **av)
{
    error(ac, av);
    if (ac == 3)
        first_option(av);
    else
        second_option(av);
    return (0);
}