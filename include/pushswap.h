/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-mathieu.brujan
** File description:
** pushswap
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

typedef struct node{
    int data;
    struct node* next;
} node;

#include <stdlib.h>
#include <unistd.h>

int pushswap(int ac, char **av);
int error(int ac, char **av);
int my_getnbr(char const *str);
int *heapsort(int *nb_array, int size);
void my_swap(int* a, int* b);

#endif /* !PUSHSWAP_H_ */
