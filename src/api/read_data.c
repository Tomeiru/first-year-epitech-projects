/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** read data
*/

#include <stdlib.h>

float *read_data_2(char **args)
{
    float *array = malloc(sizeof(float) * 32);

    if (!array)
        return (NULL);
    for (int i = 0; i < 32; i++)
        array[i] = atof(args[i + 3]);
    return (array);
}

float *read_data_3(char **args)
{
    float *ptr = malloc(sizeof(float));

    *ptr = atof(args[3]);
    return (ptr);
}

long *read_data_4(char **args)
{
    long *array = malloc(sizeof(long) * 2);

    if (!array)
        return (NULL);
    for (int i = 0; i < 2; i++)
        array[i] = atol(args[i + 3]);
    return (array);
}