/*
** EPITECH PROJECT, 2020
** defense
** File description:
** functions when it's the players' turn to defend
*/

#include "navy.h"

void defense_check(int value)
{
    if (game_struct.board[52 + value / 10 * 2 + value % 10 * 18] == '.') {
        write(1, " missed\n\n", 9);
        game_struct.board[52 + value / 10 * 2 + value % 10 * 18] = 'o';
        kill(game_struct.enemy_pid, SIGUSR2);
    }else {
        write(1, " hit\n\n", 6);
        game_struct.board[52 + value / 10 * 2 + value % 10 * 18] = 'x';
        kill(game_struct.enemy_pid, SIGUSR1);
        game_struct.enemy_hit += 1;
    }
}

int defense_ptwo(void)
{
    int value = 0;

    if (check_win() != 2)
        return (check_win);
    write(1, game_struct.board, 395);
    write(1, "waiting for enemy's attack...\n", 31);
    reset_glob();
    if (game_struct.first == 0) {
        struct sigaction actionattack;
        sigemptyset(&actionattack);
        actionattack.sa_sigaction = &register_coord;
        sigaction(SIGUSR2, &actionattack, NULL);
        sigaction(SIGUSR1, &actionattack, NULL);
        game_struct.first = 1;
    }while (game_struct.wait == 0);
    value = game_struct.x * 10 + game_struct.y;
    write(1, value_to_pos(value), 3);
    defense_check(value);
    return(attack_ptwo());
}

int defense_host(void)
{
    int value = 0;

    if (check_win() != 2)
        return (check_win);
    write(1, "waiting for enemy's attack...\n", 31);
    reset_glob();
    while (game_struct.wait == 0);
    value = game_struct.x * 10 + game_struct.y;
    write(1, value_to_pos(value), 3);
    defense_check(value);
    return(attack_host());
}