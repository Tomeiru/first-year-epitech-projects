/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** attack
*/

#include "navy.h"

void attack_ptwo(void)
{
    check_win();
    game_struct.status = 1;
    game_struct.wait = 0;
    send_signal();
    while (game_struct.wait == 0);
    defense_ptwo();
}

void attack_host(void)
{
    check_win();
    printf(game_struct.board);
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