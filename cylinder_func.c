/*
** EPITECH PROJECT, 2021
** B-MAT-100-STG-1-1-104intersection-alessandro.tosi
** File description:
** cylinder_func
*/

#include "intersection.h"

void calc_cylinder(int *point_coord, int *vector_coord, int cylinder_radius)
{
    double a = pow(vector_coord[0], 2) + pow(vector_coord[1], 2);
    double b = 2 * (point_coord[0] * vector_coord[0] + point_coord[1] * vector_coord[1]);
    double c = pow(point_coord[0], 2) + pow(point_coord[1], 2)- pow(cylinder_radius, 2);
    double delta = pow(b, 2) - (4 * a * c);

    if (point_coord[0] == vector_coord[2] && point_coord[0] == cylinder_radius) {
        printf("There is an infinite number of intersection points.\n");
        exit(0);
    }if (delta < 0) {
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

void print_data_cylinder(int *point_coord, int *vector_coord, int cylinder_radius)
{
    printf("Cylinder of radius %i\n", cylinder_radius);
    printf("Line passing through the point (%i, %i, %i)", point_coord[0], point_coord[1], point_coord[2]);
    printf(" and parallel to the vector (%i, %i, %i)\n", vector_coord[0], vector_coord[1], vector_coord[2]);
}

void cylinder_func(char **av)
{
    int *point_coord = av_to_point_coord(av);
    int *vector_coord = av_to_vector_coord(av);
    int cylinder_radius = atoi(av[8]);

    print_data_cylinder(point_coord, vector_coord, cylinder_radius);
    calc_cylinder(point_coord, vector_coord, cylinder_radius);
}