/*
** EPITECH PROJECT, 2021
** B-CPE-200-STG-2-1-matchstick-mathieu.brujan
** File description:
** main
*/

#include "matchstick.h"

int main(int ac, char **av)
{
    if (error(ac, av) == 84)
        return (84);
    return (matchstick(av));
}