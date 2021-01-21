/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** returns greater or equal prime number to the one given
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int counter = 0;

    for (int n = 2; n <= nb / 2; n++)
        if (nb % n == 0)
            counter++;
    if (nb <= 1)
        return (2);
    else if (counter == 0)
        return (nb);
    else {
        nb++;
        my_find_prime_sup(nb);
    }
    return (nb);
}
