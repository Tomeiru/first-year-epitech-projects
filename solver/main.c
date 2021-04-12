/*
** EPITECH PROJECT, 2021
** Temp
** File description:
** main
*/

#include "solver.h"

char *file_reader(char *filepath, int *len)
{
    int fd = open(filepath, O_RDONLY);
    struct stat stats;
    char *file;

    printf("LULR\n");
    if (fd == -1)
        exit(84);
    printf("LULR\n");
    if (stat(filepath, &stats) != 0)
        exit(84);
    printf("LULR\n");
    if (stats.st_size == 0)
        exit(84);
    printf("LULR\n");
    file = malloc(sizeof(char) * (stats.st_size + 1));
    if (file == NULL)
        exit(84);
    printf("LULR\n");
    if (read(fd, file, stats.st_size) == -1)
        exit(84);
    printf("LULR\n");
    file[stats.st_size] = '\0';
    *len = stats.st_size;
    close(fd);
    return (file);
}

int main(int ac, char **av)
{
    char *map;
    int len;

    error_arg(ac);
    printf("LUL\n");
    map = file_reader(av[2], &len);
    printf("LUL\n");
    error_map(map);
    printf("LUL\n");
    return (solver(map, len));
}