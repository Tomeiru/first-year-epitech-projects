/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** error
*/

#include "pong.h"

static int help(void)
{
    printf("USAGE\n    ./101pong x0 y0 z0 x1 y1 z1 n\n\n");
    printf("DESCRIPTION\n    x0  ball absissa at time t - 1\n    y0  ball ordinate at time t - 1\n    z0  ball altitude at time t - 1\n");
    printf("    x1  ball absissa at time t\n    y1  ball ordinate at time t\n    z1  ball altitude at time t\n");
    printf("    n  time shift (greater than or equal to zero, integer)\n");
    exit (84);
}

static int check_num(char **av)
{
    int j = 0;
    int counter = 0;

    for (int i = 1; av[i]; i++) {
        if (av[i][0] == '-')
            j = 1;
        else
            j = 0;
        for (j; ((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '.') && (av[i][j]!= '\0'); j++);
        if (av[i][j] != '\0') {
            write(2, "Arguments should all be numbers\n", 32);
            exit (84);
        }
        for (j = 0; av[i][j]; j++)
            if (av[i][j] == '.')
                counter++;
        if (counter > 1) {
            write(2, "Numbers shouldn't have two '.'\n", 31);
            exit (84);
        }
        for (j = 0; av[7][j]; j++)
            if (av[7][j] == '.') {
                write(2, "n can't be a float number\n", 26);
                exit (84);
            }
        counter = 0;
    }
    return (0);
}

int error(int ac, char **av)
{
    int n = 0;

    if ((ac == 2 && av[1][0] == '-' && av[1][1] == 'h') || ac != 8)
        return (help());
    check_num(av);
    n = atof(av[7]);
    if (n < 0) {
        write(2, "n must be greater or equal to zero\n", 35);
        exit (84);
    }
    return (0);
}