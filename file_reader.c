/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** file_reader
*/

#include "bsq.h"

static int error_read(int fd, int read_value, int stat_value, char *board)
{
    if (fd == -1 || read_value == -1 || stat_value != 0)
        return (84);
    if (board_check(board) == 84)
        return (84);
    return (0);
}

char *file_reader(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat stats;
    char *board;
    int read_value = 0;
    int stat_value = 0;

    if (fd == -1)
        return ("!");
    stat_value = stat(filepath, &stats);
    if (stat_value != 0)
        return ("!");
    board = malloc(sizeof(char) * (stats.st_size + 1));
    read_value = read(fd, board, stats.st_size);
    if (read_value == -1)
        return ("!");
    board[stats.st_size] = '\0';
    if (error_read(fd, read_value, stat_value, board) == 84)
        return ("!");
    close(fd);
    return (board);
}