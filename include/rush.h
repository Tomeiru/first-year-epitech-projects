/*
** EPITECH PROJECT, 2020
** rush
** File description:
** rush
*/

#ifndef RUSH_H_
#define RUSH_H_

#define BUFF_SIZE 4096
#include "my.h"

int main(void);
int rush(char *sqr);
void display(int *tab, int *res, int i, int j);
int *square_size(char *buff);
void print(char *str, int *tab);
char *rush_five(int x, int y);
char *rush_four(int x, int y);
char *rush_three(int x, int y);
char *rush_two(int x, int y);
char *rush_one(int x, int y);
char *between_lines(int b, int c, char *square, int i);
char *top_line(int a, char *square);
char *exception(int e, int f, char *square);
char *bot_line(int a, char *square);
char *top_bot_line(int a, char *square);

#endif /* !RUSH_H_ */
