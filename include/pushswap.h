/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-mathieu.brujan
** File description:
** pushswap
*/

#ifndef PUSHSWAP_H_
#define PUSHSWAP_H_

#include <stddef.h>

typedef struct node{
    int data;
    struct node* next;
} node;

void dump_list(node *head, char letter);
int error(int ac, char **av);

#endif /* !PUSHSWAP_H_ */
