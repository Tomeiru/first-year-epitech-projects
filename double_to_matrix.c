/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-102architect-alessandro.tosi
** File description:
** double_to_matrix
*/

#include "architect.h"

double *xy_to_matrix(char *x, char *y)
{
    double *result = malloc(sizeof(double) * 3);

    result[0] = atof(x);
    result[1] = atof(y);
    result[2] = 1;
    return (result);
}

double *ij_to_matrix(char *i, char *j)
{
    double *result = malloc(sizeof(double) * 9);

    result[0] = 1;
    result[1] = 0;
    result[2] = atof(i);
    result[3] = 0;
    result[4] = 1;
    result[5] = atof(j);
    result[6] = 0;
    result[7] = 0;
    result[8] = 1;
    return (result);
}

double *mn_to_matrix(char *m, char *n)
{
    double *result = malloc(sizeof(double) * 9);

    result[0] = atof(m);
    result[1] = 0;
    result[2] = 0;
    result[3] = 0;
    result[4] = atof(n);
    result[5] = 0;
    result[6] = 0;
    result[7] = 0;
    result[8] = 1;
    return (result);
}

double *rotation_angle_to_matrix(char *d)
{
    double *result = malloc(sizeof(double) * 9);

    result[0] = cos(atof(d)* (3.14159265358979323846264338327950 / 180));
    result[1] = -sin(atof(d)* (3.14159265358979323846264338327950 / 180));
    result[2] = 0;
    result[3] = sin(atof(d)* (3.14159265358979323846264338327950 / 180));
    result[4] = cos(atof(d)* (3.14159265358979323846264338327950 / 180));
    result[5] = 0;
    result[6] = 0;
    result[7] = 0;
    result[8] = 1;
    return (result);
}

double *reflection_angle_to_matrix(char *d)
{
    double *result = malloc(sizeof(double) * 9);

    result[0] = cos(2 * (atof(d)* (3.14159265358979323846264338327950 / 180)));
    result[1] = sin(2 * (atof(d)* (3.14159265358979323846264338327950 / 180)));
    result[2] = 0;
    result[3] = sin(2 * (atof(d)* (3.14159265358979323846264338327950 / 180)));
    result[4] = -cos(2 * (atof(d)* (3.14159265358979323846264338327950 / 180)));
    result[5] = 0;
    result[6] = 0;
    result[7] = 0;
    result[8] = 1;
    return (result);
}