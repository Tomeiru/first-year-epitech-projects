/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-mathieu.brujan
** File description:
** heapsort
*/

#include "pushswap.h"

void heap_to_max_heap(int *nb_array, int *size, int i)
{
    int up_pos = i;
    int left_pos = 2 * i + 1;
    int right_pos = 2 * i + 2;
    int change = 0;

    if (left_pos < *size && nb_array[left_pos] > nb_array[up_pos]) {
        my_swap(&nb_array[left_pos], &nb_array[up_pos]);
        change = 1;
    }
    if (right_pos < *size && nb_array[right_pos] > nb_array[up_pos]) {
        if (change == 1) {
            my_swap(&nb_array[right_pos], &nb_array[up_pos]);
            my_swap(&nb_array[right_pos], &nb_array[left_pos]);
        }
        else
            my_swap(&nb_array[right_pos], &nb_array[up_pos]);
        change = 2;
    }
    if (change == 1)
        heap_to_max_heap(nb_array, size, left_pos);
    if (change == 2)
        heap_to_max_heap(nb_array, size, right_pos);
}

void array_to_max_heap(int *nb_array, int *size)
{
    for (int i = (*size - 2) / 2; i >= 0; --i)
        heap_to_max_heap(nb_array, size, i);
}

int *heapsort(int *nb_array, int size)
{
    array_to_max_heap(nb_array, &size);
    while (size > 1) {
        my_swap(&nb_array[0], &nb_array[size - 1]);
        size--;
        heap_to_max_heap(nb_array, &size, 0);
    }
    return (nb_array);
}