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
node *pb_to_list(int ac, node *head, node **last);
void add_end(node **last, int data);
node *args_to_list(int ac, char **av, node *head);
void list_move(node **head_b, node **temp, node **prev, int which);

#endif /* !PUSHSWAP_H_ */
