/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "titration.h"

int main(int ac, char **av)
{
    char *file;
    int len = 0;

    error(ac);
    file = file_reader(av[1], &len);
    error_file(file, len);
    return (titration(file));
}