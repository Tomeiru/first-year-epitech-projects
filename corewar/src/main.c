/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** main
*/

#include "corewar.h"

int main(int ac, char **av)
{
    int champ_number = error_manager(ac, av);
    return (corewar(av, champ_number));
}