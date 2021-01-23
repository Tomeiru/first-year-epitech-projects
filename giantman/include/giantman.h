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

void ppm_decompression(char *file, int len);
int error(int ac, char **av);
char *file_reader(char *filepath, int *len);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_revstr(char *str);
char *my_strdup(char const *src);
int giantman(int ac, char **av);
void my_putchar(char c);


#endif /* !GIANTMAN_H_ */
