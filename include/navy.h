/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

struct exemple {
    int data1;
    int data2;
    int data3;
};

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int navy(int ac, char **av);
int main(int ac, char **av);
void error_args(int ac, char **av);
void my_swap(int *a, int *b);

#endif /* !NAVY_H_ */
