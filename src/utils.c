/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** utils
*/

float get_average(float *data, int size)
{
    float result = 0;

    for (int i = 0; i < size; i++)
        result += data[i];
    return (result / size);
}