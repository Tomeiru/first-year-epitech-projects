/*
** EPITECH PROJECT, 2020
** 103cypher
** File description:
** cypher
*/

#ifndef CYPHER_H_
#define CYPHER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int error(int ac, char **av);
int cypher(int ac, char **av);
void encryption(char **av);
char *decrypted_message_three(double *key_matrix, double *message_matrix, int len_matrix, char *message);
char *decrypted_message_two(double *key_matrix, double *message_matrix, int len_matrix, char *message);
char *decrypted_message_one(double *key_matrix, double *message_matrix, int len_matrix, char *message);
int len_matrix_finder(int len_key);
int *key_matrix_value(char *key, int len_matrix);
void decryption(char **av);

#endif /* !CYPHER_H_ */