/*
** EPITECH PROJECT, 2021
** Temp
** File description:
** main
*/

#include "generator.h"

int main(int ac, char **av)
{
    info_t *info_struct;

    error(ac, av);
    info_struct = create_and_fill_struct(ac, av);
    srand(time(NULL));
    generator(info_struct);
}