/*
** EPITECH PROJECT, 2021
** antman
** File description:
** error
*/

#include "antman.h"

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

char *filepath_to_filetype(char *filepath)
{
    char *rev_path = my_revstr(my_strdup(filepath));
    int i = 0;

    for ( ; rev_path[i] != '.' && rev_path[i] != '\0'; i++);
    if (rev_path[i] == '\0')
        return ("!");
    rev_path[++i] = '\0';
    rev_path = my_revstr(rev_path);
    return (rev_path);
}

int check_filetype(char *filepath, char *str_parameter)
{
    int parameter = str_parameter[0] - 48;
    char *filetype = filepath_to_filetype(filepath);
    if (parameter == 1 && my_strcmp(filetype, ".lyr") == 0)
        return (0);
    if (parameter == 2 && my_strcmp(filetype, ".html") == 0)
        return (0);
    if (parameter == 3 && my_strcmp(filetype, ".ppm") == 0)
        return (0);
    return (84);
}

int error(int ac, char **av)
{
    if (ac != 3)
        return (84);
    if (my_strcmp(av[2], "1") != 0 && my_strcmp(av[2], "2") != 0 &&
    my_strcmp(av[2], "3") != 0)
        return (84);
    if (check_filetype(av[1], av[2]) == 84)
        return (84);
    return (0);
}