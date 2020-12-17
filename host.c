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
        printf("\nennemy connected\n\n");
        kill(siginfo->si_pid, SIGUSR1);
    }
    //printf(board);
}

void waiting_co_host(void)
{
    struct sigaction saStruct;
    int i = 0

    sigemptyset(&saStruct.sa_mask);
    saStruct.sa_sigaction = &connected;
    saStruct.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &saStruct, NULL);
}

void host(char *filepath)
{
    int pid = getpid();
    char *pos_str = get_pos_str(filepath);
    char *board = add_boat(create_board(), pos_str);

    printf("my_pid: %i\n", pid);
    write(1, "waiting for enemy connection...\n", 33);
    while (1);
}