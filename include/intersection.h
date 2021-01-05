/*
** EPITECH PROJECT, 2020
** 103cypher
** File description:
** cypher
*/

#ifndef CYPHER_H_
#define CYPHER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

void sphere_func(char **av);
void cylinder_func(char **av);
void cone_func(char **av);
int error(int ac, char **av);
int *av_to_vector_coord(char **av);
int *av_to_point_coord(char **av);
void print_single(int *point_coord, int *vector_coord, double t);
void print_double(int *point_coord, int *vector_coord, double *t);
double get_single_t(double a, double b);
double *get_double_t(double a, double b, double delta);
int intersection(int ac, char **av);

#endif /* !CYPHER_H_ */