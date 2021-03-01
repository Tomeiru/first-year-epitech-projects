/*
** EPITECH PROJECT, 2021
** B-MAT-200-STG-2-1-106bombyx-alessandro.tosi
** File description:
** error
*/

#include "bombyx.h"

void help(void)
{
    write(2, "USAGE\n    ./106bombyx n [k | i0 i1]\n\nDESCRIPTION\n    n       number of first generation indivuals\n    k       growth rate from 1 to 4\n    i0      initial generation (included)\n    i1      final generation (included)\n", 216);
    exit(84);
}

void check_args_first(char **av)
{
    int nb = 0;

    for (int i = 0; av[1][i]; i++) {
        if (!(av[1][i] >= '0' && av[1][i] <= '9')) {
            write(2, "Wrong first argument, see -h\n", 29);
            exit(84);
        }
    }if (atoi(av[1]) == 0) {
        write(2, "Wrong first argument, see -h\n", 29);
        exit(84);
    }for (int i = 0; av[2][i]; i++) {
        if (!((av[2][i] >= '0' && av[2][i] <= '9') || (av[2][i] == '.'))) {
            write(2, "Wrong second argument, see -h\n", 30);
            exit(84);
        }if (av[2][i] == '.')
            nb++;
        if (nb > 1) {
            write(2, "Wrong second argument, see -h\n", 30);
            exit(84);
        }
    }if (atof(av[2]) < 1 || atof(av[2]) > 4) {
        write(2, "Wrong second argument, see -h\n", 30);
        exit(84);
    }
}

void check_args_second(char **av)
{
    for (int j = 1; av[j]; j++) {
        for (int i = 0; av[j][i]; i++) {
            if (!(av[j][i] >= '0' && av[j][i] <= '9')) {
                write(2, "Wrong argument, see -h\n", 23);
                exit(84);
            }
        }if (atoi(av[j]) == 0) {
            write(2, "Wrong argument, see -h\n", 23);
            exit(84);
        }
    }
}

void error_args(int ac, char **av)
{
    if (ac == 3)
        check_args_first(av);
    else
        check_args_second(av);
}

void error(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0)
        help();
    if (ac != 3 && ac != 4) {
        write(2, "Wrong number of arguments, see -h\n", 34);
        exit (84);
    }error_args(ac, av);
}