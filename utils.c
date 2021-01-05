/*
** EPITECH PROJECT, 2021
** B-MAT-100-STG-1-1-104intersection-alessandro.tosi
** File description:
** utils
*/

#include "intersection.h"

double *get_double_t(double a, double b, double delta)
{
    double *t = malloc(sizeof(double) * 2);

    if (a == 0) {
        t[0] = -b - sqrt(delta);
        t[1] = -b + sqrt(delta);
    }else {
        t[0] = (-b - sqrt(delta)) / (2 * a);
        t[1] = (-b + sqrt(delta)) / (2 * a);
    }
    return (t);
}

double get_single_t(double a, double b)
{
    double t = 0;

    if (a == 0)
        t = -b;
    else
        t = -b / (2 * a);
    return (t);
}

void print_double(int *point_coord, int *vector_coord, double *t)
{
    double xa = point_coord[0] + t[1] * vector_coord[0];
    double ya = point_coord[1] + t[1] * vector_coord[1];
    double za = point_coord[2] + t[1] * vector_coord[2];
    double xb = point_coord[0] + t[0] * vector_coord[0];
    double yb = point_coord[1] + t[0] * vector_coord[1];
    double zb = point_coord[2] + t[0] * vector_coord[2];

    printf("(%.3f, %.3f, %.3f)\n", xa, ya, za);
    printf("(%.3f, %.3f, %.3f)\n", xb, yb, zb);
}

void print_single(int *point_coord, int *vector_coord, double t)
{
    double x = point_coord[0] + t * vector_coord[0];
    double y = point_coord[1] + t * vector_coord[1];
    double z = point_coord[2] + t * vector_coord[2];

    printf("(%.3f, %.3f, %.3f)\n", x, y, z);
}

int *av_to_vector_coord(char **av)
{
    int *vector_coord = malloc(sizeof(int) * 3);

    vector_coord[0] = atoi(av[5]); 
    vector_coord[1] = atoi(av[6]);
    vector_coord[2] = atoi(av[7]);
    return (vector_coord);
}

int *av_to_point_coord(char **av)
{
    int *point_coord = malloc(sizeof(int) * 3);

    point_coord[0] = atoi(av[2]); 
    point_coord[1] = atoi(av[3]);
    point_coord[2] = atoi(av[4]);
    return (point_coord);
}
