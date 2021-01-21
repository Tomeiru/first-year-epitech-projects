/*
** EPITECH PROJECT, 2021
** B-CPE-110-STG-1-1-antman-mathieu.brujan
** File description:
** giantman
*/

#ifndef GIANTMAN_H_
#define GIANTMAN_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../lib/my/my.h"

int main(int, char **);
int giantman(int, char **);
int error_manager(int, char **);
char *file_reader(char *, int *);
void choose_algorithm(char *, int, int);
void ppm_decompression(char *, int);
int get_new_len(char *);
int get_index(char *);
void decompress_and_print(char *, int, int);

#endif /* !GIANTMAN_H_ */
