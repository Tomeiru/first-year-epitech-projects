/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-mathieu.brujan
** File description:
** ai_turn
*/

#include "matchstick.h"

int get_random_line(game_t *game)
{
    int line = 0;
    
    srand(time(0));
    line = rand() % game->lines + 1;
    if (game->board_nbr[line - 1] == 0)
        return (-1);
    return (line);
}

int get_random_matches(game_t *game, int line)
{
    int matches = 0;

    srand(time(0));
    if (game->max > game->board_nbr[line - 1])
        matches = rand() % game->board_nbr[line - 1] + 1;
    else
        matches = rand() % game->max + 1;
    return (matches);
}

void ai_line_and_matches(game_t *game)
{
    int line = -1;
    int matches = 0;

    while (line == -1)
        line = get_random_line(game);
    matches = get_random_matches(game, line);
    write(1, "AI removed ", 11);
    my_putnbr(matches);
    write(1, " match(es) from line ", 21);
    my_putnbr(line);
    remove_from_board(game, line, matches);
}

int ai_turn(game_t *game)
{
    write(1, "\n", 1);
    write(1, "AI's turn...\n", 13);
    ai_line_and_matches(game);
    if (check_lose(game) == 1) {
        write(1, "I lost... snif... but I'll get you next time!!\n", 47);
        return (1);
    }return (user_turn(game));
}