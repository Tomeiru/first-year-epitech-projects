/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** fill_info_struct
*/

#include "asm.h"

static char *file_reader(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat stats;
    char *file;

    if (fd == -1 || stat(filepath, &stats) != 0 || stats.st_size == 0)
        return("!");
    file = malloc(sizeof(char) * (stats.st_size + 1));
    if (file == NULL)
        return("!");
    if (read(fd, file, stats.st_size) == -1)
        return("!");
    file[stats.st_size] = '\0';
    close(fd);
    return (file);
}

static char ***fill_files_array(int ac, char **av)
{
    char ***files = malloc(sizeof(char **) * (ac));

    for (int i = 0; i < ac - 1; i++)
        files[i] = str_to_array(file_reader(av[i + 1]));
    files[ac - 1] = NULL;
    return (files);
}

info_t *fill_info_struct(int ac, char **av)
{
    info_t *info = malloc(sizeof(info_t));

    info->files = fill_files_array(ac, av);
    av++;
    info->filenames = av;
    info->return_value = 0;
    info->nb_files = ac - 1;
    return (info);
}