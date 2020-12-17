/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** player_two
*/

#include "navy.h"

void *connection_success(int signum, siginfo_t *siginfo, void *context)
{
    if (signum == SIGUSR1)
        printf("successfully connected\n\n");
}

void waiting_co_player_two(void)
{
    struct sigaction saStruct;

    sigemptyset(&saStruct.sa_mask);
    saStruct.sa_sigaction = &connection_success;
    saStruct.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &saStruct, NULL);
    while(1);
}

void player_two(int host_pid, char *filepath)
{
    int pid = getpid();
    char *pos_str = get_pos_str(filepath);
    char *board = add_boat(create_board(), pos_str);

    printf("my_pid: %i\n", pid);
    kill(host_pid, SIGUSR2);
    waiting_co_player_two();
}