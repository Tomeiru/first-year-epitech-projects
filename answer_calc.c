/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** answer_calc
*/

#include "pong.h"

double *vector_dif(double *A, double *B)
{
    double *res_vec = malloc(sizeof(double) * 3);

    for (int i = 2; i >= 0; i--)
        res_vec[i] = A[i] - B[i];
    return (res_vec);
}

double *vector_sum(double *A, double *B)
{
    double *res_vec = malloc(sizeof(double) * 3);

    for (int i = 2; i >= 0; i--)
        res_vec[i] = A[i] + B[i];
    return (res_vec);
}

double vector_coef(double *v)
{
    double res = 0;
    double x = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];

    res = sqrt(x);
    return (res);
}

double answer_calc(double *vec_minus_one, double *vec_zero, int n)
{
    double *vec_dif = vector_dif(vec_zero, vec_minus_one);
    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\n", vec_dif[0], vec_dif[1], vec_dif[2]);
    double *vec_value = vector_sum(vec_zero, vec_dif);
    double vec_coef;
    double x;
    double inc_angle;
    double val_bef;
    double val_aft;
    int board = 0;

    if (vec_zero[2] < 0)
        val_bef = -1;
    else
        val_bef = 1;
    if (vec_value[2] < 0)
        val_aft = -1;
    else
        val_aft = 1;
    if (val_bef != val_aft || vec_value[2] == 0)
        board = 1;
    for (int i = 1; i < n; i++) {
        if (vec_value[2] < 0)
            val_bef = -1;
        else
            val_bef = 1;
        vec_value = vector_sum(vec_value, vec_dif);
        if (vec_value[2] < 0)
            val_aft = -1;
        else
            val_aft = 1;
        if (val_bef != val_aft || vec_value[2] == 0)
            board = 1;
    }
    vec_coef = vector_coef(vec_dif);
    x = (vec_dif[2]/vec_coef);
    inc_angle = (asin(x) / 0.017453);
    printf("At time t + %i, ball coordinates will be:\n(%.2f, %.2f, %.2f)\n", n, vec_value[0], vec_value[1], vec_value[2]);
    if (board == 1) {
        if (inc_angle < 0)
            printf("The incidence angle is:\n%.2f degrees\n", -inc_angle);
        else
            printf("The incidence angle is:\n%.2f degrees\n", inc_angle);
    }
    else
        printf("The ball won't reach the paddle.\n");
}