/*
** EPITECH PROJECT, 2020
** rush
** File description:
** rush
*/

#ifndef RUSH_H_
#define RUSH_H_

#define BUFF_SIZE 8192
#include "my.h"

int main(void);
int rush(char *sqr, int j);
int counter (int *res);
void display(int *tab, int *res, int i, int j);
int *square_size(char *buff);
void print(char *str, int *tab);
char *rush_five(int x, int y);
char *rush_four(int x, int y);
char *rush_three(int x, int y);
char *rush_two(int x, int y);
char *rush_one(int x, int y);

#endif /* !RUSH_H_ */
