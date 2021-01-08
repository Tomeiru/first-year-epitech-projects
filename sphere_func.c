/*
** EPITECH PROJECT, 2021
** B-MAT-100-STG-1-1-104intersection-alessandro.tosi
** File description:
** sphere_func
*/

#include "intersection.h"

void calc_sphere(int *point_coord, int *vector_coord, int sphere_radius)
{
    double a = pow(vector_coord[0], 2) + pow(vector_coord[1], 2) + pow(vector_coord[2], 2);
    double b = 2 * (point_coord[0] * vector_coord[0] + point_coord[1] * vector_coord[1] + point_coord[2] * vector_coord[2]);
    double c = pow(point_coord[0], 2) + pow(point_coord[1], 2) + pow(point_coord[2], 2) - pow(sphere_radius, 2);
    double delta = pow(b, 2) - (4 * a * c);

    if (delta < 0) {
        printf("No intersection point.\n");
        exit(0);
    }if (delta == 0) {
        printf("1 intersection point:\n");
        double t = get_single_t(a, b);
        print_single(point_coord, vector_coord, t);
    }if (delta > 0) {
        printf("2 intersection points:\n");
        double *two_t = get_double_t(a, b, delta);
        print_double(point_coord, vector_coord, two_t);
    }
}

void print_data_sphere(int *point_coord, int *vector_coord, int sphere_radius)
{
    printf("Sphere of radius %i\n", sphere_radius);
    printf("Line passing through the point (%i, %i, %i)", point_coord[0], point_coord[1], point_coord[2]);
    printf(" and parallel to the vector (%i, %i, %i)\n", vector_coord[0], vector_coord[1], vector_coord[2]);
}

void sphere_func(char **av)
{
    int *point_coord = av_to_point_coord(av);
    int *vector_coord = av_to_vector_coord(av);
    int sphere_radius = atoi(av[8]);

    print_data_sphere(point_coord, vector_coord, sphere_radius);
    calc_sphere(point_coord, vector_coord, sphere_radius);
}