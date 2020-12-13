/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

#include "pushswap.h"

void list_move(node **head_b, node **temp, node **prev, int which)
{
    if (which == 0) {
        if (*temp == *head_b)
            *head_b = (*head_b)->next;
        else 
            (*prev)->next = (*temp)->next;
        if ((*temp)->next == NULL)
            *temp = *head_b;
        else
            *temp = (*temp)->next;
    }
    if (which == 1) {
        *prev = *temp;
        if ((*temp)->next == NULL)
            *temp = *head_b;
        else
            *temp = (*temp)->next;
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    int number = 0;

    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == '-')
            sign = sign * -1;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10;
            number = number + str[i] - '0';
        }
    }
    number = number * sign;
    return (number);
}