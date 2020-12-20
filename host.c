/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** host
*/

#include "navy.h"

void *connected(int signum, siginfo_t *siginfo, void *context)
{
    if (signum == SIGUSR2) {
        if (game_struct.start == 0) {
            write(1, "\nenemy connected\n\n", 18);
            game_struct.enemy_pid = siginfo->si_pid;
            kill(siginfo->si_pid, SIGUSR1);
            game_struct.start = 1;
        }
        game_struct.wait = 1;
    }
}

void waiting_co_host(void)
{
    struct sigaction actionstart;

    sigemptyset(&actionstart.sa_mask);
    actionstart.sa_sigaction = &connected;
    actionstart.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &actionstart, NULL);
    while (game_struct.wait == 0);
}

int host(char *filepath)
{
    char *pos_str = get_pos_str(filepath);

    game_struct.board = add_boat(create_board(), pos_str);
    game_struct.pid = getpid();
    write(1, "my_pid: ", 8);
    my_put_nbr(game_struct.pid);
    write(1, "\n", 1);
    write(1, "waiting for enemy connection...\n", 33);
    waiting_co_host();
    game_struct.wait = 0;
    return (attack_host());
}