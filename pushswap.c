/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-mathieu.brujan
** File description:
** pushswap
*/

#include "pushswap.h"

void dump_list(node *head, char letter) 
{
    node *temp = head;

    while (temp != NULL) {
        printf("list %c : %i\n", letter, temp->data);
        temp = temp->next;
    }
}

node *add_beg(node *head, int data)
{
    node *new_node = malloc(sizeof(node));

    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return (head);
}

node *args_to_list(int ac, char **av, node *head_a)
{
    for (int i = ac - 1; i > 0; i--)
        head_a = add_beg(head_a, my_getnbr(av[i]));
    return (head_a);
}

int pushswap(int ac, char **av)
{
    node *head_a = NULL;
    node *head_b = NULL;

    if (error(ac, av) == 84)
        return (84);
    head_a = args_to_list(ac, av, head_a);
    //printf("avant\n");
    //dump_list(head_a, 'a');
    for (int j = 0; j < ac - 2; j++) {
    for (int i = 0; i < ac - 3; i++) {
        if (head_a->data >= head_a->next->data) {
            rotate(&head_a);
            //printf("first\n");
            //dump_list(head_a, 'a');
        }
        else if (head_a->data < head_a->next->data) {
            swap(&head_a);
            rotate(&head_a);
            //printf("second\n");
            //dump_list(head_a, 'a');
        }
    }
    
    push(&head_a, &head_b);
    /*printf("end\n");
    dump_list(head_a, 'a');
    printf("otherlist\n");
    dump_list(head_b, 'b');*/
    }
    for (int j = 0; j < ac - 2; j++)
        push(&head_b, &head_a);
    printf("final\n");
    dump_list(head_a, 'a');
}