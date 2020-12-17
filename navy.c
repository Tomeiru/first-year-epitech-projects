/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** navy
*/

#include "navy.h"

char *get_pos_str(char *pos_file)
{
    int fd = open(pos_file, O_RDONLY);
    struct stat stats;
    char *pos_str;

    if (fd == -1 || stat(pos_file, &stats) == -1)
        error_write(1);
    pos_str = malloc(sizeof(char) * (stats.st_size + 1));
    if (read(fd, pos_str, stats.st_size) == -1)
        error_write(1);
    pos_str[stats.st_size] = '\0';
    close(fd);
    return (pos_str);
}

int navy(int ac, char **av)
{
    error_args(ac, av);
    if (ac == 2)
        host(av[1]);
    else
        player_two(my_getnbr(av[1]), av[2]);
    return (0);
}