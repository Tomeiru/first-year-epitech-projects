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
    my_putstr(infinadd(argv[1], argv[2]));
    my_putchar('\n');
    return (0);
}