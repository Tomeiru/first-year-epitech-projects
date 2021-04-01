/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper3-lilou.stoll-metz
** File description:
** main
*/

#include "stumper.h"

int main(int ac, char **av)
{
    info_t *info_struct = malloc(sizeof(info_t));

    error(ac, av, info_struct);
    crocus(info_struct);
    return (0);
}
