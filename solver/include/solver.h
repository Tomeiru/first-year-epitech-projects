/*
** EPITECH PROJECT, 2021
** Temp
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int solver(char *map, int len);
void error(int ac, char **av);
void error_map(char *map);
void error_arg(int ac);

#endif /* !SOLVER_H_ */
