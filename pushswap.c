/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-mathieu.brujan
** File description:
** push_swap
*/

#include "pushswap.h"

char *add_a_move_to_moves(char *moves, char *move, int *size)
{
    char *new_moves = malloc(sizeof(char) * (*size + 4));
    int i = 0;
    int j = 0;

    *size += 3;
    for ( ; moves[i]; i++)
        new_moves[i] = moves[i];
    for ( ; j < 3; j++)
        new_moves [i + j] = move[j];
    new_moves[i + j] = '\0';
    free(moves);
    return (new_moves);
}

void final_print(node *ops, int size)
{
    char *print = malloc(sizeof(char) * (size + 1));
    char *ops_str[4] = {
        "pb ", "pa ", "pa\n", "rb "
    };
    int j = 0;
    node *prev = NULL;

    for ( ; ops != NULL; ops = ops->next) {
        free(prev);
        prev = ops;
        for (int i = 0; i < 4; i++)
            if (i == ops->data) {
                print[j++] = ops_str[i][0];
                print[j++] = ops_str[i][1];
                print[j++] = ops_str[i][2];
            }
    }
    print[j] = '\0';
    write(1, print, size);
    free(print);
}

void move_print(int *sorted, node *head_b, int ac)
{
    node *temp = head_b;
    node *prev = NULL;
    node *ops = NULL;
    node *last_op = NULL;
    int size = (ac - 1) * 3;

    ops = pb_to_list(ac, ops, &last_op);
    for (int i = ac - 2; i >= 0; i--) {
        while (sorted[i] != temp->data) {
            add_end(&last_op, 3);
            size += 3;
            prev = temp;
            if (temp->next == NULL)
                temp = head_b;
            else
                temp = temp->next;
        }
        if (i == 0)
            add_end(&last_op, 2);
        else
            add_end(&last_op, 1);
        size += 3;
        if (temp == head_b)
            head_b = head_b->next;
        else 
            prev->next = temp->next;
        if (temp->next == NULL)
            temp = head_b;
        else
            temp = temp->next;
    }
    free(sorted);
    final_print(ops, size);
}

int check_unsorted(int *unsorted, int ac)
{
    for (int i = 0; i < ac - 2; i++)
        if (unsorted[i] > unsorted[i + 1])
            return (0);
    return (1);
}

int pushswap(int ac, char **av)
{
    int *unsorted = malloc(sizeof(int) * (ac - 1));
    int size = ac - 1;
    int *sorted;
    node *head_b = NULL;

    head_b = args_to_list(ac, av, head_b);
    if (ac == 2) {
        write(1, "\n", 1);
        return (0);
    }
    for (int i = 1; i < ac; i++)
        unsorted[i - 1] = my_getnbr(av[i]);
    if (check_unsorted(unsorted, ac) == 1) {
        write(1, "\n", 1);
        return (0);
    }
    sorted = heapsort(unsorted, size);
    move_print(sorted, head_b, ac);
    return (0);
}