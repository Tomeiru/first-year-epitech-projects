/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int ac, char **av, char **env);
int mysh(char **env, int return_val);
void error(int ac, char **av);
int my_strlen(char const *str);
int get_input_len(char *input);
char *get_input(int *input_len, int return_val);
int is_it_builtin(char *command);
int builtin(char **command, char **env);
int is_number(char *str);
int my_getnbr(char const *str);
int is_alphanum(char *str);
int is_number(char *str);
char *my_strdup(char const *src);
int builtin_cd(char **command, char **env);
int builtin_unsetenv(char **command, char **env);
int builtin_setenv(char **command, char **env);
int builtin_env(char **env);
int builtin_exit(char **command, char **env);
int my_strcmp(char const *s1, char const *s2);

#endif /* !NAVY_H_ */