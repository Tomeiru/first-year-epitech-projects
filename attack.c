/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** attack
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
            game_struct.board[251 + game_struct.value_sent / 10 * 2 +
            game_struct.value_sent % 10 * 18] = 'x';
            game_struct.hit += 1;
            write(1, " hit\n\n", 6);
        }if (signum == SIGUSR2) {
            game_struct.board[251 + game_struct.value_sent / 10 * 2 +
            game_struct.value_sent % 10 * 18] = 'o';
            write(1, " missed\n\n", 9);
        }game_struct.wait = 1;
    }
}

int error_stdin(char *input)
{
    int pos = 0;

    if (strlen(input) > 3) {
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
    if (game_struct.board[251 + pos / 10 * 2 + pos % 10 * 18] != '.') {
        write(1, "wrong position\n", 16);
        return (-1);
    }
    return (0);
}

int stdin_to_pos()
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
    else
        if (error_stdin(input) == -1)
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

void defense_host(void)
{
    char *pos;
    int value = 0;

    check_win();
    write(1, "waiting for enemy's attack...\n", 31);
    reset_glob();
    while (game_struct.wait == 0);
    value = game_struct.x * 10 + game_struct.y;
    pos = value_to_pos(value);
    write(1, pos, 3);
    if (game_struct.board[52 + value / 10 * 2 + value % 10 * 18] == '.') {
        write(1, " missed\n\n", 9);
        game_struct.board[52 + value / 10 * 2 + value % 10 * 18] = 'o';
        kill(game_struct.enemy_pid, SIGUSR2);
    }
    else {
        write(1, " hit\n\n", 6);
        game_struct.board[52 + value / 10 * 2 + value % 10 * 18] = 'x';
        kill(game_struct.enemy_pid, SIGUSR1);
        game_struct.enemy_hit += 1;
    }
    attack_host();
}

void attack_ptwo(void)
{
    check_win();
    game_struct.status = 1;
    game_struct.wait = 0;
    send_signal();
    while (game_struct.wait == 0);
    defense_ptwo();
}

void enemy_won(void)
{
    printf(game_struct.board);
    write(1, "Enemy won\n\n", 12);
    exit(1);
}

void i_won(void)
{
    printf(game_struct.board);
    write(1, "I won\n\n", 8);
    exit(0);
}

void check_win(void)
{
    if (game_struct.enemy_hit == 14)
        enemy_won();
    if (game_struct.hit == 14)
        i_won();
}

void reset_glob(void)
{
    game_struct.wait = 0;
    game_struct.status = 2;
    game_struct.signal_received_x = 0;
    game_struct.signal_received_y = 0;
    game_struct.x = 0;
    game_struct.y = 0;
}

void defense_ptwo(void)
{
    char *pos;
    int value = 0;

    check_win();
    printf(game_struct.board);
    write(1, "waiting for enemy's attack...\n", 31);
    reset_glob();
    if (game_struct.first == 0) {
        struct sigaction actionattack;
        sigemptyset(&actionattack);
        actionattack.sa_sigaction = &register_coord;
        sigaction(SIGUSR2, &actionattack, NULL);
        sigaction(SIGUSR1, &actionattack, NULL);
        game_struct.first = 1;
    }
    while (game_struct.wait == 0);
    value = game_struct.x * 10 + game_struct.y;
    pos = value_to_pos(value);
    write(1, pos, 3);
    if (game_struct.board[52 + value / 10 * 2 + value % 10 * 18] == '.') {
        write(1, " missed\n\n", 9);
        game_struct.board[52 + value / 10 * 2 + value % 10 * 18] = 'o';
        kill(game_struct.enemy_pid, SIGUSR2);
    }
    else {
        write(1, " hit\n\n", 6);
        game_struct.board[52 + value / 10 * 2 + value % 10 * 18] = 'x';
        kill(game_struct.enemy_pid, SIGUSR1);
        game_struct.enemy_hit += 1;
    }
    attack_ptwo();
}