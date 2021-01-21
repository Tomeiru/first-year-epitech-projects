/*
** EPITECH PROJECT, 2021
** antman
** File description:
** antman
*/

#ifndef ANTMAN_H_
#define ANTMAN_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../lib/my/my.h"

int main(int, char **);
int antman(int, char **);
int error_manager(int, char **);
int check_filetype(char *, char *);
char *filepath_to_filetype(char *);
char *file_reader(char *, int *);
void choose_algorithm(char *, int, int);
void ppm_compression(char *, int);
int get_new_len(char *, int);
int get_index(char *, int);
int conditions(char *reverse_file, int *i);
unsigned char compress_number(char *, int *);

#endif /* !ANTMAN_H_ */