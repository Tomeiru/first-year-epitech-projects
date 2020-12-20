/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** attack
*/

#include "navy.h"

int attack_ptwo(void)
{
    if (check_win() != 2)
        return (check_win);
    game_struct.status = 1;
    game_struct.wait = 0;
    send_signal();
    while (game_struct.wait == 0);
    defense_ptwo();
}

int attack_host(void)
{
    if (check_win() != 2)
        return (check_win);
    write(1, game_struct.board, 395);
    game_struct.status = 1;
    game_struct.wait = 0;
    if (game_struct.first == 0) {
        struct sigaction actionattack;
        sigemptyset(&actionattack);
        actionattack.sa_sigaction = &register_coord;
        sigaction(SIGUSR2, &actionattack, NULL);
        sigaction(SIGUSR1, &actionattack, NULL);
        game_struct.first = 1;
    }
    send_signal();
    while (game_struct.wait == 0);
    defense_host();
}