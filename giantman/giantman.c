/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** giantman
*/

#include "giantman.h"

void lyr_decompression(char *file, int len)
{
}

void html_decompression(char *file, int len)
{
}

void choose_algorithm(char *file, int parameter, int len)
{
    if (parameter == 1)
        lyr_decompression(file, len);
    if (parameter == 2)
        html_decompression(file, len);
    if (parameter == 3)
        ppm_decompression(file, len);
}

int giantman(int ac, char **av)
{
    char *file;
    int len = 0;

    if (error_manager(ac, av) == 84)
        return (84);
    file = file_reader(av[1], &len);
    if (my_strcmp(file, "!") == 0)
        return (84);
    choose_algorithm(file, av[2][0] - 48, len);
    return (0);
}