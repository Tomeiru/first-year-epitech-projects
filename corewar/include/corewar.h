/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//main.c
int main(int ac, char **av);

//lib_fct.c
int my_strcmp(char *s1, char *s2);
int my_strlen(char *str);

//error_manager.c
void error_manager(int ac, char **av);
int check_args(int ac, char **av);
int *args_counter(int ac, char **av);
int check_cor(char *cor, char *str);

//file_errors.c
int file_errors(int ac, char **av, int cor);

//corewar.c
int corewar(int ac, char **av);

#endif /* !COREWAR_H_ */
