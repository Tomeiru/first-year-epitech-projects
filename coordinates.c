/*
** EPITECH PROJECT, 2020
** coordinates
** File description:
** functions used to get and register coordinates
*/

#include "navy.h"

void register_cord(int which_one)
{
    if (which_one == 1) {
        if (game_struct.signal_received_x == 0)
            game_struct.x += 1;
        else
            game_struct.y += 1;
    } if (which_one == 2) {
        if (game_struct.signal_received_x == 0)
            game_struct.signal_received_x = 1;
        else if (game_struct.signal_received_y == 0)
            game_struct.signal_received_y = 1;
    }
}

void *register_coord(int signum, siginfo_t *siginfo, void *context)
{
    if (game_struct.status == 2) {
        if (signum == SIGUSR2) {
            register_cord(1);
        }if (signum == SIGUSR1) {
            register_cord(2);
        }if (game_struct.signal_received_x == 1 && game_struct.signal_received_y == 1)
            game_struct.wait = 1;
    }if (game_struct.status == 1) {
        write(1, value_to_pos(game_struct.pos), 3);
        if (signum == SIGUSR1) {
            game_struct.board[252 + game_struct.value_sent / 10 * 2 +
            game_struct.value_sent % 10 * 18] = 'x';
            game_struct.hit += 1;
            write(1, " hit\n\n", 6);
        }if (signum == SIGUSR2) {
            game_struct.board[252 + game_struct.value_sent / 10 * 2 +
            game_struct.value_sent % 10 * 18] = 'o';
            write(1, " missed\n\n", 9);
        }game_struct.wait = 1;
    }
}