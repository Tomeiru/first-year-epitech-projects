/*
** EPITECH PROJECT, 2020
** help
** File description:
** prints the help message
*/

#include "navy.h"

void help(void)
{
    int fd = open("help", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 204);

    read(fd, buffer, 204);
    write(1, buffer, 204);
    free(buffer);
    close(fd);
    exit(84);
}