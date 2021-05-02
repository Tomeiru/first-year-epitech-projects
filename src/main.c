/*
** EPITECH PROJECT, 2021
** 110borwein
** File description:
** main
*/

#include "borwein.h"

int main(int ac, char **av)
{
    error(ac, av);
    borwein(atoi(av[1]));
    return (0);
}