/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** readers
*/

#include <unistd.h>

unsigned char read_uchar(int fd)
{
    unsigned char value = 0;

    read(fd, &value, sizeof(char));
    return (value);
}

int read_int(int fd)
{
    char int_buffer[sizeof(int)];
    int value = 0;

    read(fd, int_buffer, sizeof(int));
    value = *((int*) int_buffer);
    return (value);
}

float read_float(int fd)
{
    char float_buffer[sizeof(float)];
    float value = 0;

    read(fd, float_buffer, sizeof(float));
    value = *((float*) float_buffer);
    return (value);
}