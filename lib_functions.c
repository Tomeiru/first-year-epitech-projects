/*
** EPITECH PROJECT, 2020
** lib_functions
** File description:
** functions taken from libmy needed for this project
*/

#include "navy.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    int number = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '-')
            sign *= -1;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            number *= 10;
            number += str[i] - '0';
        }
    }
    number *= sign;
    return (number);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *dest_pointer = dest;

    if (dest[0] == '\0' && src[0] == '\0')
        return (0);
    for ( ; dest_pointer[i] != '\0'; i++);
    for ( ; src[j] != '\0'; i++) {
        dest_pointer[i] = src[j];
        j++;
    }
    dest_pointer[i] = '\0';
    return (dest);
}