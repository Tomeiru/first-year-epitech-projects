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
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char *str);

//error_manager.c
int error_manager(int ac, char **av);
int check_args(int ac, char **av);
int *args_counter(int ac, char **av);
int check_cor(char *cor, char *str);

//flag_errors.c
int flag_errors(int ac, char **av);

//corewar.c
int corewar(int ac, char **av);

#endif /* !COREWAR_H_ */
