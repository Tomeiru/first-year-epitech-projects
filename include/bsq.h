/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** bsq.h
*/

#ifndef BSQ_H_
#define BSQ_H_

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int bsq(int ac, char **av);
int main(int ac, char **av);
char *file_reader(char *filepath);
int board_check(char *board);
int my_get_first_line(char *board);
void algorithm(char *board, int len_board, int line_len);

#endif /* !BSQ_H_ */