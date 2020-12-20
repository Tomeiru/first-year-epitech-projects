/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <stdio.h>

int main(int ac, char **av);
int navy(int ac, char **av);
int error_args(int ac, char **av);
void init_struct(void);
int host(char *filepath);
int player_two(int host_pid, char *filepath);
int my_getnbr(char const *str);
void help_error(void);
int check_pos_file(char *pos_file);
char *get_pos_str(char *pos_file);
int check_format(char *pos_str);
int check_content(char *pos_str);
int pos_to_value(char letter, char number);
char *value_to_pos(int value);
int error_write(int value);
void init_struct(void);
char *get_pos_str(char *pos_file);
char *create_board(void);
char *my_strcat(char *dest, char const *src);
char *add_boat(char *board, char *pos_str);
char *place_boats(char *board, int pos_first, int pos_sec, int value);
void my_swap(int *a, int *b);
void waiting_co_host(void);
void *connected(int signum, siginfo_t *siginfo, void *context);
int attack_host(void);
int check_win(void);
int enemy_won(void);
int i_won(void);
void print_in_color(char *board);
void my_putchar(char c);
void *register_coord(int signum, siginfo_t *siginfo, void *context);
void register_cord(int which_one);
void send_signal(void);
int stdin_to_pos();
int error_stdin(char *input);
int defense_host(void);
void reset_glob(void);
int attack_ptwo(void);
int defense_ptwo(void);
void my_put_nbr(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);

struct game_stats
{
    int pid;
    int enemy_pid;
    int wait;
    int hit;
    int enemy_hit;
    int signal_rec_x;
    int signal_rec_y;
    int x;
    int y;
    int start;
    int pos;
    int status;
    int first;
    int value_sent;
    int win_written;
    char *board;
};

extern struct game_stats game_struct;

#endif /* !NAVY_H_ */