/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** error
*/

#include "navy.h"

int error_write(int value)
{
    if (value == 1) {
        write(2, "An error occured during the opening of the file.\n", 50);
        return (84);
    }if (value == 2) {
        write(2, "An error has been detected in your boats' position\n", 52);
        return (84);
    }
    return (0);
}

int check_pos_file(char *pos_file)
{
    char *pos_str = get_pos_str(pos_file);

    if (pos_str[0] == '!')
        return (84);
    if (check_format(pos_str) == 84 || check_content(pos_str) == 84)
        return (84);
}

int error_args(int ac, char **av)
{
    if (ac == 1 || ac > 3 || (ac == 2 && my_strcmp(av[1], "-h") == 0)) {
        help_error();
        return (84);
    }if (ac == 2) {
        if (check_pos_file(av[1]) == 84)
            return (84);
    }else {
        if (check_pos_file(av[2]) == 84)
            return (84);
    }return (0);
}