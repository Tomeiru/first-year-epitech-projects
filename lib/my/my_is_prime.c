/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** returns 1 if number is prime, 0 if not
*/

#include "my.h"

int my_is_prime(int nb)
{
    int counter = 0;

    for (int n = 2; n <= nb / 2; n++)
        if (nb % n == 0)
            counter++;
    if (nb <= 1)
        return (0);
    else if (counter == 0)
        return (1);
    else
        return (0);
}
