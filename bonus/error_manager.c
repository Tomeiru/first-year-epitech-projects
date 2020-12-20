/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** error
*/

#include "navy.h"

void error_write(int value)
{
    if (value == 1) {
        write(2, "An error occured during the opening of the file.\n", 50);
        exit(84);
    }if (value == 2) {
        write(2, "An error has been detected in your boats' position\n", 52);
        exit(84);
    }
}

void check_pos_file(char *pos_file)
{
    char *pos_str = get_pos_str(pos_file);

    check_format(pos_str);
    check_content(pos_str);
}

void error_args(int ac, char **av)
{
    if (ac == 1 || ac > 3 || (ac == 2 && strcmp(av[1], "-h") == 0))
        help();
    if (ac == 2)
        check_pos_file(av[1]);
    else
        check_pos_file(av[2]);
}