/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-mathieu.brujan
** File description:
** error
*/

#include "my_sokoban.h"

void check_empty(char *file)
{
    if (file[0] == '\0')
        exit(84);
}

void check_format(char *file, struct game_struct *game)
{
    int P_count = 0;
    int X_count = 0;
    int O_count = 0;

    check_empty(file);
    for (int i = 0; file[i]; i++) {
        if (file[i] != 'P' && file[i] != '#' && file[i] != 'O'
        && file[i] != ' ' && file[i] != '\n' && file[i] != 'X')
            exit(84);
        if (file[i] == 'O')
            O_count++;
        if (file[i] == 'X')
            X_count++;
        if (file[i] == 'P')
            P_count++;
    }if (P_count != 1 || X_count != O_count || X_count == 0)
        exit(84);
    game->nb_of_boxes = X_count;
}

void error_file(char *file, struct game_struct *game)
{
    if (file[0] == '!' && file[1] == '\0')
        exit(84);
    check_format(file, game);
}

void help(void)
{
    write(1, "USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map  file ", 55);
    write(1, "representing the warehouse map, containing '#' for walls,\n", 58);
    write(1, "          'P' for the player, 'X' for boxes and 'O' for ", 56);
    write(1, "storage locations.\n", 19);
    exit(84);
}

void error_args(int ac, char **av)
{
    if (ac != 2)
        exit(84);
    if (my_strcmp(av[1], "-h") == 0)
        help();
}