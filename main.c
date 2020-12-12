/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-mathieu.brujan
** File description:
** main
*/

#include "pushswap.h"

int main(int ac, char **av)
{
    if (error(ac, av) == 84) {
        write(2, "Error: bad arguments\n", 21);
        return (84);
    }
    if (ac > 50000)
        return (0);
    return (pushswap(ac, av));
}