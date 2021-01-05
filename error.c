/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** error
*/

#include "intersection.h"

static int help(void)
{
    printf("USAGE\n    ./104intersection opt xp yp zp xv yv zv p\n\n");
    printf("DESCRIPTION\n    opt             surface option: 1 for a sphere, 2 for a cylinder, 3 for a cone\n    (xp, yp, zp)    coordinates of a point by which the light ray passes through\n");
    printf("    (xv, yv, zv)    coordinates of a vector parallel to the light ray\n    p               parameter: radius of the sphere, radius of the cylinder, or angle formed by the cone and the Z-axis\n");
    exit(84);
}

static void check_args(char **av)
{
    int j = 0;

    if (strcmp(av[1], "1") != 0 && strcmp(av[1], "2") != 0 && strcmp(av[1], "3") != 0) {
        printf("Error: the flag must be one (for a sphere) or two (for a cylinder) or three (for a cone), currently '%s'\n", av[1]);
        exit(84);
    }for (int i = 2; i < 9; i++) {
        if (av[i][0] == '-')
            j = 1;
        else
            j = 0;
        for ( ; (av[i][j] >= '0' && av[i][j] <= '9') && (av[i][j]!= '\0'); j++);
        if (av[i][j] != '\0') {
            write(2, "Error: Arguments 2 to 9 should all be numbers\n", 38);
            exit(84);
        }
    }
}

int error(int ac, char **av)
{
    if ((ac == 2 && av[1][0] == '-' && av[1][1] == 'h') || ac != 9)
        return (help());
    check_args(av);
    return (0);
}