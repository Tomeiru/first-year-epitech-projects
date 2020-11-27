/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** error
*/

#include "architect.h"

static int help(void)
{
    printf("USAGE\n    ./102architect x y transfo1 arg11 [arg12] [transfo2 arg21 [arg22]] ...\n\n");
    printf("DESCRIPTION\n    x   absissa of the original point\n    y   ordinate of the original point\n\n");
    printf("    transfo arg1 [arg2]\n    -t i j  translation along vector (i, j)\n    -z m n  scaling by factors m (x-axis) and n (y-axis)\n");
    printf("    -r d    rotation centered in 0 by a d degree angle\n    -s d    reflection over the axis passing through 0 with an inclination angle of d degrees\n");
    exit(84);
}

static void check_args(char **av)
{
    int j = 0;
    int counter = 0;

    for (int i = 1; i < 3; i++) {
        counter = 0;
        if (av[i][0] == '-')
            j = 1;
        else
            j = 0;
        for ( ; ((av[i][j] >= '0' && av[i][j] <= '9') || av[i][j] == '.') && (av[i][j]!= '\0'); j++);
        if (av[i][j] != '\0') {
            write(2, "Error: x and y should both be numbers\n", 38);
            exit(84);
        }
        for (j = 0; av[i][j]; j++)
            if (av[i][j] == '.')
                counter++;
        if (counter > 1) {
            write(2, "Error: Numbers shouldn't have two '.'\n", 38);
            exit(84);
        }
    }
    for (int i = 3; av[i]; i++) {
        if (strcmp(av[i], "-t") != 0 && strcmp(av[i], "-z") != 0 && strcmp(av[i], "-r") != 0 && strcmp(av[i], "-s") != 0) {
            printf("Error: Argument %i should be a valid transformation argument (-t, -z, -r, -s), currently '%s'\n", i + 1, av[i]);
            exit(84);
        }
        if (strcmp(av[i], "-t") == 0 || strcmp(av[i], "-z") == 0) {
            if (av[i + 1] == NULL || av[i + 2] == NULL) {
                printf("Error: %s needs two number arguments to work\n", av[i]);
                exit(84);
            }
            for (int k = i + 1; k < i + 3; k++) {
                counter = 0;
                if (av[k][0] == '-')
                    j = 1;
                else
                    j = 0;
                for ( ; ((av[k][j] >= '0' && av[k][j] <= '9') || av[k][j] == '.') && (av[k][j]!= '\0'); j++);
                if (av[k][j] != '\0') {
                    printf("Error: %s arguments should both be numbers\n", av[i]);
                    exit(84);
                }
                for (j = 0; av[k][j]; j++)
                    if (av[k][j] == '.')
                        counter++;
                if (counter > 1) {
                    write(2, "Error: Numbers shouldn't have two '.'\n", 38);
                    exit(84);
                }
            }
            i += 2;
        }
        if (strcmp(av[i], "-r") == 0 || strcmp(av[i], "-s") == 0) {
            if (av[i + 1] == NULL) {
                printf("Error: %s needs a number argument to work\n", av[i]);
                exit(84);
            }
            counter = 0;
            if (av[i + 1][0] == '-')
                j = 1;
            else
                j = 0;
            for ( ; ((av[i + 1][j] >= '0' && av[i + 1][j] <= '9') || av[i + 1][j] == '.') && (av[i + 1][j]!= '\0'); j++);
            if (av[i + 1][j] != '\0') {
                printf("Error: %s argument should be a number\n", av[i]);
                exit(84);
            }
            for (j = 0; av[i + 1][j]; j++)
                if (av[i + 1][j] == '.')
                    counter++;
            if (counter > 1) {
                write(2, "Error: Numbers shouldn't have two '.'\n", 38);
                exit(84);
            }
            i++;
        }
    }
}

int error(int ac, char **av)
{
    if ((ac == 2 && av[1][0] == '-' && av[1][1] == 'h') || ac < 5)
        return (help());
    check_args(av);
    return (0);
}