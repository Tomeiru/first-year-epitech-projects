/*
** EPITECH PROJECT, 2020
** send_signal
** File description:
** sends signal to corresponding player
*/

#include "navy.h"

int error_stdin(char *input)
{
    int pos = 0;

    if (my_strlen(input) > 3) {
        write(1, "wrong position\n", 16);
        return (-1);
    } if (input[0] > 'H' || input[0] < 'A') {
        write(1, "wrong position\n", 16);
        return (-1);
    } if (input[1] < '1' || input[1] > '8') {
        write(1, "wrong position\n", 16);
        return (-1);
    }
    pos = pos_to_value(input[0], input[1]);
    if (game_struct.board[252 + pos / 10 * 2 + pos % 10 * 18] != '.') {
        write(1, "wrong position\n", 16);
        return (-1);
    }
    return (0);
}

int stdin_to_pos(void)
{
    char *input = malloc(sizeof(char) * 3);
    int size = 2;
    int getline_value = 0;
    int value = 0;

    write(1, "attack: ", 9);
    getline_value = getline(&input, &size, stdin);
    if (getline_value == -1) {
        write(1, "wrong position\n", 16);
        return (-1);
    }
    else if (error_stdin(input) == -1)
        return (-1);
    value = pos_to_value(input[0], input[1]);
    game_struct.value_sent = value;
    free(input);
    return (value);
}

void send_signal(void)
{
    int pos = stdin_to_pos();

    for ( ; pos == -1; pos = stdin_to_pos());
    game_struct.pos = pos;
    for (int i = 0; i < pos / 10; i++) {
        kill(game_struct.enemy_pid, SIGUSR2);
        usleep(100);
    } kill(game_struct.enemy_pid, SIGUSR1);
    usleep(100);
    for (int i = 0; i < pos % 10; i++) {
        kill(game_struct.enemy_pid, SIGUSR2);
        usleep(100);
    } kill(game_struct.enemy_pid, SIGUSR1);
    usleep(100);
}