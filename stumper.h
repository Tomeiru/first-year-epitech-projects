/*
** EPITECH PROJECT, 2021
** duo_stumper2
** File description:
** stumper
*/

#ifndef STUMPER_H_
#define STUMPER_H_

typedef struct game_s {
    int win;
    int width;
    int height;
    int turn;
    char p1;
    char p2;
    char referee;
    char current_player;
    char **map;
} game_t;

game_t *init_game(int ac, char **av);

#endif /* !STUMPER_H_ */
