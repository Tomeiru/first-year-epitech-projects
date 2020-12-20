/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** player_two
*/

#include "navy.h"

void *connection_success(int signum, siginfo_t *siginfo, void *context)
{
    if (signum == SIGUSR1 && game_struct.start == 0) {
        printf("successfully connected\n\n");
        game_struct.wait = 1;
        game_struct.start = 1;
        printf(game_struct.board);
    }
}

void waiting_co_player_two(void)
{
    struct sigaction actionstart;

    sigemptyset(&actionstart.sa_mask);
    actionstart.sa_sigaction = &connection_success;
    actionstart.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &actionstart, NULL);
    while (game_struct.wait == 0);
}

void player_two(int host_pid, char *filepath)
{
    char *pos_str = get_pos_str(filepath);

    game_struct.board = add_boat(create_board(), pos_str);
    game_struct.pid = getpid();
    game_struct.enemy_pid = host_pid;
    printf("my_pid: %i\n", game_struct.pid);
    kill(host_pid, SIGUSR2);
    waiting_co_player_two();
    defense_ptwo();
}