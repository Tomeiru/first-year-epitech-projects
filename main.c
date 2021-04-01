/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper3-lilou.stoll-metz
** File description:
** main
*/

#include "stumper.h"

void exit_and_free(int value, info_t *info_struct)
{
    free(info_struct);
    exit(value);
}

static void error(int ac, char **av, info_t *info_struct)
{
    if (ac != 3 && ac != 5)
        exit_and_free(84, info_struct);
    for (int i = 1; av[i]; i++)
        if (strlen(av[i]) < 1)
            exit_and_free(84, info_struct);
    if (ac == 3)
        error_three_arg(av, info_struct);
    else
        error_five_arg(av, info_struct);
}

static void free_end(info_t *info_struct)
{
    free(info_struct->chars);
    free(info_struct->numbers);
    for (int i = 0; i < 5; i++)
        free(info_struct->array[i]);
    free(info_struct->array);
    exit_and_free(0, info_struct);
}

int main(int ac, char **av)
{
    info_t *info_struct = malloc(sizeof(info_t));

    if (info_struct == NULL)
        return (84);
    error(ac, av, info_struct);
    init_struct(info_struct);
    crocus(info_struct);
    free_end(info_struct);
    return (0);
}
