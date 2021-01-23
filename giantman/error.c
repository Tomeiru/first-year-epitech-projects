/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** error
*/

#include "giantman.h"

char *file_reader(char *filepath, int *len)
{
    int fd = open(filepath, O_RDONLY);
    struct stat stats;
    char *file;

    if (fd == -1)
        return ("!");
    if (stat(filepath, &stats) != 0)
        return ("!");
    if (stats.st_size == 0)
        return ("empty");
    file = malloc(sizeof(char) * (stats.st_size + 1));
    if (file == NULL)
        return ("!");
    if (read(fd, file, stats.st_size) == -1)
        return ("!");
    file[stats.st_size] = '\0';
    *len = stats.st_size;
    close(fd);
    return (file);
}

int error(int ac, char **av)
{
    if (ac != 3)
        return (84);
    if (my_strcmp(av[2], "1") != 0 && my_strcmp(av[2], "2") != 0 &&
    my_strcmp(av[2], "3") != 0)
        return (84);
    return (0);
}