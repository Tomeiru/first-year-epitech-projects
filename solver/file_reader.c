/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** file_reader
*/

#include "solver.h"

char *file_reader(char *filepath, int *len)
{
    int fd = open(filepath, O_RDONLY);
    struct stat stats;
    char *file;

    if (fd == -1 || stat(filepath, &stats) != 0 || stats.st_size == 0)
        exit(84);
    file = malloc(sizeof(char) * (stats.st_size + 1));
    if (file == NULL)
        exit(84);
    if (read(fd, file, stats.st_size) == -1)
        exit(84);
    file[stats.st_size] = '\0';
    *len = stats.st_size;
    close(fd);
    return (file);
}