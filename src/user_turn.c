/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-mathieu.brujan
** File description:
** user_turn
*/

#include "matchstick.h"

int get_line(game_t *game)
{
    char *line = NULL;
    int num = 0;
    unsigned long size = 0;

    if (getline(&line, &size, stdin) == -1)
        return (-2);
    size = my_strlen(line) - 1;
    line[size] = '\0';
    num = error_line(game, line);
    if (num == -1)
        return (-1);
    return (num);
}

int get_matches(game_t *game, int line)
{
    char *matches = NULL;
    int num = 0;
    unsigned long size = 0;

    if (getline(&matches, &size, stdin) == -1)
        return (-2);
    size = my_strlen(matches) - 1;
    matches[size] = '\0';
    num = error_matches(game, line, matches);
    if (num == -1)
        return (-1);
    return (num);
}

int line_and_matches(game_t *game)
{
    int line = 0;
    int matches = 0;

    write(1, "Line: ", 6);
    line = get_line(game);
    if (line == -1)
        return (84);
    if (line == -2)
        return (-1);
    write(1, "Matches: ", 9);
    matches = get_matches(game, line);
    if (matches == -1)
        return (84);
    if (matches == -2)
        return (-1);
    write(1, "Player removed ", 15);
    my_putnbr(matches);
    write(1, " match(es) from line ", 21);
    my_putnbr(line);
    remove_from_board(game, line, matches);
    return (0);
}

int user_turn(game_t *game)
{
    int return_value = 84;

    write(1, "\n", 1);
    write(1, "Your turn:\n", 11);
    while (return_value == 84)
        return_value = line_and_matches(game);
    if (return_value == -1)
        return (0);
    if (check_lose(game) == 1) {
        write(1, "You lost, too bad...\n", 21);
        return (2);
    }return (ai_turn(game));
}