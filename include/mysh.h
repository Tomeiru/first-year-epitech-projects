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

int main(int ac, char **av, char **env);
int mysh(char **env, int return_val);
void error(int ac, char **av);
int my_strlen(char const *str);

#endif /* !NAVY_H_ */