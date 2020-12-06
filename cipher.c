/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** 101pong
*/

#include "cipher.h"

int cypher(int ac, char **av)
{
    error(ac, av);
    if (av[3][0] == '0')
        encryption(av);
    else
        decryption(av);
    return (0);
}