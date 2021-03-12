/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-mathieu.brujan
** File description:
** error
*/

#include "matchstick.h"

int error_matches(game_t *game, int line, char *matches)
{
    int num = 0;

    for (int i = 0; matches[i] != '\0'; i++) {
        if (!(matches[i] >= '0' && matches[i] <= '9')) {
            write(1, "Error: invalid input (positive number expected)\n", 48);
            return (-1);
        }
    }num = my_getnbr(matches);
    if (num == 0) {
        write(1, "Error: you have to remove at least one match\n", 45);
        return (-1);
    }if (num > game->max) {
        write(1, "Error: you cannot remove more than ", 35);
        my_putnbr(game->max);
        write(1, " matches per turn\n", 18);
        return (-1);
    }if (num > game->board_nbr[line - 1]) {
        write(1, "Error: not enough matches on this line\n", 39);
        return (-1);
    }return (num);
}

int error_line(game_t *game, char *line)
{
    int num = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (!(line[i] >= '0' && line[i] <= '9')) {
            write(1, "Error: invalid input (positive number expected)\n", 48);
            return (-1);
        }
    }num = my_getnbr(line);
    if (num == 0 || num > game->lines) {
        write(1, "Error: this line is out of range\n", 34);
        return (-1);
    }if (game->board_nbr[num - 1] == 0) {
        write(1, "Error: this line is out of matchstick\n", 38);
        return (-1);
    }return (num);
}

int error(int ac, char **av)
{
    if (ac != 3)
        return (84);
    for (int i = 0; av[1][i]; i++)
        if (!(av[1][i] >= '0' && av[1][i] <= '9'))
            return (84);
    for (int i = 0; av[2][i]; i++)
        if (!(av[1][i] >= '0' && av[1][i] <= '9'))
            return (84);
    if (my_getnbr(av[1]) <= 1 || my_getnbr(av[2]) <= 0)
        return (84);
    return (0);
}
