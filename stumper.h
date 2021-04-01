/*
** EPITECH PROJECT, 2021
** duo_stumper3
** File description:
** stumper
*/

#ifndef STUMPER_H_
#define STUMPER_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct info_s {
    int width;
    int lenght_chars;
    char *numbers;
    char *chars;
    char **array;
} info_t;

void write_zero(info_t *info, int i);
void write_one(info_t *info, int i);
void write_two(info_t *info, int i);
void write_three(info_t *info, int i);
void write_four(info_t *info, int i);
void write_five(info_t *info, int i);
void write_six(info_t *info, int i);
void write_seven(info_t *info, int i);
void write_eight(info_t *info, int i);
void write_nine(info_t *info, int i);
void exit_and_free(int value, info_t *info_struct);
void error_three_arg(char **av, info_t *info_struct);
void error_five_arg(char **av, info_t *info_struct);
void crocus(info_t *info_struct);
void init_struct(info_t *info);

#endif /* !STUMPER_H_ */
