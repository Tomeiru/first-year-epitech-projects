/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

int navy(int ac, char **av);
int main(int ac, char **av);
void error_args(int ac, char **av);
void my_swap(int *a, int *b);
void error_write(int value);
void host(char *filepath);
void player_two(int host_pid, char *filepath);
int my_getnbr(char const *str);
void init_struct(void);
char *get_pos_str(char *pos_file);
int pos_to_value(char letter, char number);

struct game_stats
{
    int pid;
    int enemy_pid;
    int wait;
    int hit;
    int enemy_hit;
    int signal_received_x;
    int signal_received_y;
    int x;
    int y;
    int start;
    int pos;
    int status;
    int first;
    int value_sent;
    char *board;
};

extern struct game_stats game_struct;

#endif /* !NAVY_H_ */
