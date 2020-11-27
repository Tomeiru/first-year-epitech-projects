/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** answer_calc
*/

#include "architect.h"

double *translation(double *xy_matrix, char *i, char *j)
{
    double *ij_matrix = ij_to_matrix(i, j);
    double *result_matrix = malloc(sizeof(double) * 3);

    result_matrix[0] = xy_matrix[0] + ij_matrix[2];
    result_matrix[1] = xy_matrix[1] + ij_matrix[5];
    result_matrix[2] = 1;
    free(ij_matrix);
    return (result_matrix);
}

double *scaling(double *xy_matrix, char *m, char *n) {
    double *mn_matrix = mn_to_matrix(m, n);
    double *result_matrix = malloc(sizeof(double) * 3);

    result_matrix[0] = xy_matrix[0] * mn_matrix[0];
    result_matrix[1] = xy_matrix[1] * mn_matrix[4];
    result_matrix[2] = 1;
    free(mn_matrix);
    return (result_matrix);
}

double *rotation(double *xy_matrix, char *d) {
    double *rotation_matrix = rotation_angle_to_matrix(d);
    double *result_matrix = malloc(sizeof(double) * 3);

    result_matrix[0] = xy_matrix[0] * rotation_matrix[0] + xy_matrix[1] * rotation_matrix[1];
    result_matrix[1] = xy_matrix[0] * rotation_matrix[3] + xy_matrix[1] * rotation_matrix[4];
    result_matrix[2] = 1;
    free(rotation_matrix);
    return (result_matrix);
}

double *reflection(double *xy_matrix, char *d) {
    double *reflection_matrix = reflection_angle_to_matrix(d);
    double *result_matrix = malloc(sizeof(double) * 3);

    result_matrix[0] = xy_matrix[0] * reflection_matrix[0] + xy_matrix[1] * reflection_matrix[1];
    result_matrix[1] = xy_matrix[0] * reflection_matrix[3] + xy_matrix[1] * reflection_matrix[4];
    result_matrix[2] = 1;
    free(reflection_matrix);
    return (result_matrix);
}

void answer_calc(char **av)
{
    double *basexy_matrix = xy_to_matrix(av[1], av[2]);
    double *xy_matrix = xy_to_matrix(av[1], av[2]);

    for (int i = 3; av[i]; i++) {
        if (strcmp(av[i], "-t") == 0) {
            printf("Translation along vector (%s, %s)\n", av[i + 1], av[i + 2]);
            xy_matrix = translation(xy_matrix, av[i + 1], av[i + 2]);
            i += 2;
        }
        if (strcmp(av[i], "-z") == 0) {
            printf("Scaling by factors %s and %s\n", av[i + 1], av[i + 2]);
            xy_matrix = scaling(xy_matrix, av[i + 1], av[i + 2]);
            i += 2;
        }
        if (strcmp(av[i], "-r") == 0) {
            printf("Rotation by a %s degree angle\n", av[i + 1]);
            xy_matrix = rotation(xy_matrix, av[i + 1]);
            i++;
        }
        if (strcmp(av[i], "-s") == 0) {
            printf("Reflection over an axis with an inclination angle of %s degrees\n", av[i + 1]);
            xy_matrix = reflection(xy_matrix, av[i + 1]);
            i++;
        }
    }
    modifier_matrix(av);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", basexy_matrix[0], basexy_matrix[1], xy_matrix[0], xy_matrix[1]);
    free(basexy_matrix);
    free(xy_matrix);
}