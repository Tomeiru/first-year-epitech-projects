/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "infinadd.h"
#include "my.h"
char *infinsub(char *fst_num, char *sec_num);

int main(int argc, char **argv)
{
    if (argc == 1)
        return (84);
    my_putstr(infinsub(argv[1], argv[2]));
    my_putchar('\n');
    return (0);
}