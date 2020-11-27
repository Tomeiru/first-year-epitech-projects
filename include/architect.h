/*
** EPITECH PROJECT, 2020
** 102architect
** File description:
** architect
*/

#ifndef ARCHITECT_H_
#define ARCHITECT_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

int main(int ac, char **av);
int error(int ac, char **av);
int architect(int ac, char **av);
void modifier_matrix(char **av);
void answer_calc(char **av);
double *ij_to_matrix(char *i, char *j);
double *mn_to_matrix(char *m, char *n);
double *rotation_angle_to_matrix(char *d);
double *reflection_angle_to_matrix(char *d);
double *xy_to_matrix(char *x, char *y);

#endif /* !ARCHITECT_H_ */
