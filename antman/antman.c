/*
** EPITECH PROJECT, 2021
** antman
** File description:
** antman
*/

#include "antman.h"

void lyr_compression(char *file, int len)
{
}

void html_compression(char *file, int len)
{
}

void choose_algorithm(char *file, int parameter, int len)
{
    if (parameter == 1)
        lyr_compression(file, len);
    if (parameter == 2)
        html_compression(file, len);
    if (parameter == 3)
        ppm_compression(file, len);
}

int antman(int ac, char **av)
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