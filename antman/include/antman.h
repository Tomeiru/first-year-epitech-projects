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

int error(int ac, char **av);
char *file_reader(char *filepath, int *len);
int my_strcmp(char const *s1, char const *s2);
int antman(int ac, char **av);
char *my_revstr(char *str);
char *my_strdup(char const *src);
int my_strlen(char const *str);
void ppm_compression(char *file, int len);
void my_putchar(char c);
int get_index(char *file, int len);

#endif /* !ANTMAN_H_ */