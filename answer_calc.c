/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** answer_calc
*/

#include "pong.h"

float *vector_dif(float *A, float *B)
{
    float *res_vec = malloc(sizeof(float) * 3);

    for (int i = 2; i >= 0; i--)
        res_vec[i] = A[i] - B[i];
    return (res_vec);
}

float *vector_sum(float *A, float *B)
{
    float *res_vec = malloc(sizeof(float) * 3);

    for (int i = 2; i >= 0; i--)
        res_vec[i] = A[i] + B[i];
    return (res_vec);
}

float vector_coef(float *v)
{
    float res = 0;
    float x = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];

    res = sqrt(x);
    return (res);
}

float answer_calc(float *vec_minus_one, float *vec_zero, int n)
{
    float *vec_dif = vector_dif(vec_zero, vec_minus_one);
    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\n", vec_dif[0], vec_dif[1], vec_dif[2]);
    float *vec_value = vector_sum(vec_zero, vec_dif);
    float vec_coef;
    float x;
    float inc_angle;
    float val_bef;
    float val_aft;
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
        printf("The ball won’t reach the paddle.\n");
}