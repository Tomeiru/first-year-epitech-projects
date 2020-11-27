/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** answer_calc
*/

#include "architect.h"

double *translation_mod(double *xy_matrix, char *i, char *j)
{
    double *ij_matrix = ij_to_matrix(i, j);

    if (xy_matrix[0] == 0 && xy_matrix[1] == 0 && xy_matrix[2] == 0 &&
    xy_matrix[3] == 0 && xy_matrix[4] == 0 && xy_matrix[5] == 0 &&
    xy_matrix[6] == 0 && xy_matrix[7] == 0 && xy_matrix[8] == 0)
        return (ij_matrix);
    else {
        double *result_matrix = malloc(sizeof(double) * 9);
        result_matrix[0] = ij_matrix[0] * xy_matrix[0] + ij_matrix[1] * xy_matrix[3] + ij_matrix[2] * xy_matrix[6];
        result_matrix[1] = ij_matrix[0] * xy_matrix[1] + ij_matrix[1] * xy_matrix[4] + ij_matrix[2] * xy_matrix[7];
        result_matrix[2] = ij_matrix[0] * xy_matrix[2] + ij_matrix[1] * xy_matrix[5] + ij_matrix[2] * xy_matrix[8];
        result_matrix[3] = ij_matrix[3] * xy_matrix[0] + ij_matrix[4] * xy_matrix[3] + ij_matrix[5] * xy_matrix[6];
        result_matrix[4] = ij_matrix[3] * xy_matrix[1] + ij_matrix[4] * xy_matrix[4] + ij_matrix[5] * xy_matrix[7];
        result_matrix[5] = ij_matrix[3] * xy_matrix[2] + ij_matrix[4] * xy_matrix[5] + ij_matrix[5] * xy_matrix[8];
        result_matrix[6] = 0;
        result_matrix[7] = 0;
        result_matrix[8] = 1;
        free(ij_matrix);
        return (result_matrix);
    }
}

double *scaling_mod(double *xy_matrix, char *m, char *n) {
    double *mn_matrix = mn_to_matrix(m, n);

    if (xy_matrix[0] == 0 && xy_matrix[1] == 0 && xy_matrix[2] == 0 &&
    xy_matrix[3] == 0 && xy_matrix[4] == 0 && xy_matrix[5] == 0 &&
    xy_matrix[6] == 0 && xy_matrix[7] == 0 && xy_matrix[8] == 0)
        return (mn_matrix);
    else {
        double *result_matrix = malloc(sizeof(double) * 9);
        result_matrix[0] = mn_matrix[0] * xy_matrix[0] + mn_matrix[1] * xy_matrix[3] + mn_matrix[2] * xy_matrix[6];
        result_matrix[1] = mn_matrix[0] * xy_matrix[1] + mn_matrix[1] * xy_matrix[4] + mn_matrix[2] * xy_matrix[7];
        result_matrix[2] = mn_matrix[0] * xy_matrix[2] + mn_matrix[1] * xy_matrix[5] + mn_matrix[2] * xy_matrix[8];
        result_matrix[3] = mn_matrix[3] * xy_matrix[0] + mn_matrix[4] * xy_matrix[3] + mn_matrix[5] * xy_matrix[6];
        result_matrix[4] = mn_matrix[3] * xy_matrix[1] + mn_matrix[4] * xy_matrix[4] + mn_matrix[5] * xy_matrix[7];
        result_matrix[5] = mn_matrix[3] * xy_matrix[2] + mn_matrix[4] * xy_matrix[5] + mn_matrix[5] * xy_matrix[8];
        result_matrix[6] = 0;
        result_matrix[7] = 0;
        result_matrix[8] = 1;
        free(mn_matrix);
        return (result_matrix);
    }
}

double *rotation_mod(double *xy_matrix, char *d) {
    double *rotation_matrix = rotation_angle_to_matrix(d);

    if (xy_matrix[0] == 0 && xy_matrix[1] == 0 && xy_matrix[2] == 0 &&
    xy_matrix[3] == 0 && xy_matrix[4] == 0 && xy_matrix[5] == 0 &&
    xy_matrix[6] == 0 && xy_matrix[7] == 0 && xy_matrix[8] == 0)
        return (rotation_matrix);
    else {
        double *result_matrix = malloc(sizeof(double) * 9);
        result_matrix[0] = rotation_matrix[0] * xy_matrix[0] + rotation_matrix[1] * xy_matrix[3] + rotation_matrix[2] * rotation_matrix[6];
        result_matrix[1] = rotation_matrix[0] * xy_matrix[1] + rotation_matrix[1] * xy_matrix[4] + rotation_matrix[2] * rotation_matrix[7];
        result_matrix[2] = rotation_matrix[0] * xy_matrix[2] + rotation_matrix[1] * xy_matrix[5] + rotation_matrix[2] * rotation_matrix[8];
        result_matrix[3] = rotation_matrix[3] * xy_matrix[0] + rotation_matrix[4] * xy_matrix[3] + rotation_matrix[5] * rotation_matrix[6];
        result_matrix[4] = rotation_matrix[3] * xy_matrix[1] + rotation_matrix[4] * xy_matrix[4] + rotation_matrix[5] * rotation_matrix[7];
        result_matrix[5] = rotation_matrix[3] * xy_matrix[2] + rotation_matrix[4] * xy_matrix[5] + rotation_matrix[5] * rotation_matrix[8];
        result_matrix[6] = 0;
        result_matrix[7] = 0;
        result_matrix[8] = 1;
        free(rotation_matrix);
        return (result_matrix);
    }
}

double *reflection_mod(double *xy_matrix, char *d) 
{
    double *reflection_matrix = reflection_angle_to_matrix(d);

    if (xy_matrix[0] == 0 && xy_matrix[1] == 0 && xy_matrix[2] == 0 &&
    xy_matrix[3] == 0 && xy_matrix[4] == 0 && xy_matrix[5] == 0 &&
    xy_matrix[6] == 0 && xy_matrix[7] == 0 && xy_matrix[8] == 0)
        return (reflection_matrix);
    else {
        double *result_matrix = malloc(sizeof(double) * 9);
        result_matrix[0] = reflection_matrix[0] * xy_matrix[0] + reflection_matrix[1] * xy_matrix[3] + reflection_matrix[2] * xy_matrix[6];
        result_matrix[1] = reflection_matrix[0] * xy_matrix[1] + reflection_matrix[1] * xy_matrix[4] + reflection_matrix[2] * xy_matrix[7];
        result_matrix[2] = reflection_matrix[0] * xy_matrix[2] + reflection_matrix[1] * xy_matrix[5] + reflection_matrix[2] * xy_matrix[8];
        result_matrix[3] = reflection_matrix[3] * xy_matrix[0] + reflection_matrix[4] * xy_matrix[3] + reflection_matrix[5] * xy_matrix[6];
        result_matrix[4] = reflection_matrix[3] * xy_matrix[1] + reflection_matrix[4] * xy_matrix[4] + reflection_matrix[5] * xy_matrix[7];
        result_matrix[5] = reflection_matrix[3] * xy_matrix[2] + reflection_matrix[4] * xy_matrix[5] + reflection_matrix[5] * xy_matrix[8];
        result_matrix[6] = 0;
        result_matrix[7] = 0;
        result_matrix[8] = 1;
        free(reflection_matrix);
        return (result_matrix);
    }
}

void modifier_matrix(char **av)
{
    double *modifier_mat = malloc(sizeof(double) * 9);

    for (int i = 0; i < 9; i++) {
        modifier_mat[i] = 0;
    }
    for (int i = 3; av[i]; i++) {
        if (strcmp(av[i], "-t") == 0) {
            modifier_mat = translation_mod(modifier_mat, av[i + 1], av[i + 2]);
            i += 2;
        }
        if (strcmp(av[i], "-z") == 0) {
            modifier_mat = scaling_mod(modifier_mat, av[i + 1], av[i + 2]);
            i += 2;
        }
        if (strcmp(av[i], "-r") == 0) {
            modifier_mat = rotation_mod(modifier_mat, av[i + 1]);
            i++;
        }
        if (strcmp(av[i], "-s") == 0) {
            modifier_mat = reflection_mod(modifier_mat, av[i + 1]);
            i++;
        }
    }
    printf("%-8.2f%-8.2f%.2f\n%-8.2f%-8.2f%.2f\n%-8.2f%-8.2f%.2f\n", modifier_mat[0], modifier_mat[1], modifier_mat[2], modifier_mat[3], modifier_mat[4], modifier_mat[5], modifier_mat[6], modifier_mat[7], modifier_mat[8]);
    free(modifier_mat);
}