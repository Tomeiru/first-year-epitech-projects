/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-mathieu.brujan
** File description:
** push
*/

#include "pushswap.h"

void push(node **head_a, node **head_b)
{
    if (*head_a == NULL)
        return;
    (*head_b) = add_beg(*head_b, (*head_a)->data);
    if ((*head_a)->next == NULL)
        (*head_a) = NULL;
    else
        (*head_a) = (*head_a)->next;
}

void swap(node **head)
{
    node *temp = *head;
    node *temp_second = *head;

    if (*head == NULL || (*head)->next == NULL)
        return;
    temp = temp->next;
    temp_second = temp_second->next;
    temp_second = temp_second->next;
    (*head)->next = temp_second;
    (*head) = add_beg(*head, temp->data);
}

void rotate(node **head)
{
    node *temp = *head;
    node *new_node = malloc(sizeof(node));
    new_node->data = (*head)->data;
    new_node->next = NULL;

    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    *head = (*head)->next;
}

void reverse_rotate(node **head)
{
    node *temp = *head;
    node *temp_second = *head;

    printf("yo\n");
    while (temp_second->next->next != NULL)
        temp_second = temp_second->next;
    while (temp->next != NULL)
        temp = temp->next;
    (*head) = add_beg(*head, temp->data);
    temp_second->next = NULL;
}