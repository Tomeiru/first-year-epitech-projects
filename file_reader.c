/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-mathieu.brujan
** File description:
** file_reader
*/

#include "my_sokoban.h"

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