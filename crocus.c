/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper3-lilou.stoll-metz
** File description:
** main
*/

#include "stumper.h"

int crocus(info_t *info_struct)
{
    void (* print_nbr[10])(info_t *, int) = {
    write_zero, write_one, write_two, write_three, write_four,
    write_five, write_six, write_seven, write_eight, write_nine,
    };

    for (int i = 0; info_struct->numbers[i]; i++)
        print_nbr[info_struct->numbers[i] - '0'](info_struct, i * 6);
    for (int i = 0; info_struct->array[i]; i++)
        printf("%s\n", info_struct->array[i]);
}
