/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-mathieu.brujan
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

typedef struct game_s {
    int lines;
    int max;
    char **board;
    int *board_nbr;
    int line_size;
} game_t;

int my_getnbr(char const *str);
int my_strlen(char const *str);
int my_putnbr(int nb);
char *my_revstr(char *str);
void remove_from_board(game_t *game, int line, int matches);
int check_lose(game_t *game);
int user_turn(game_t *game);
game_t *ini_struct(char **av);
void print_board(game_t *game);
void my_putchar(char c);
int error_line(game_t *game, char *line);
int error_matches(game_t *game, int line, char *matches);
int ai_turn(game_t *game);
int error(int ac, char **av);
int matchstick(char **av);

#endif /* !MATCHSTICK_H_ */
