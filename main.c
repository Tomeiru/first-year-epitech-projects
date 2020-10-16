/*
** EPITECH PROJECT, 2020
** infinadd
** File description:
** main
*/

#include "infinadd.h"
#include "my.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        return (84);
    if (error(argc, argv) == 84)
        return (84);
    infinadd(argv[1], argv[2]);
    return (0);
}