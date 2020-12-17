/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-mathieu.brujan
** File description:
** error
*/

#include "navy.h"

void help(void)
{
    int fd = open("help", O_RDONLY);
    char *buffer = malloc(sizeof(char) * 204);

    read(fd, buffer, 204);
    write(1, buffer, 204);
    free(buffer);
    close(fd);
    exit(84);
}

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

void check_format(char *pos_str)
{
    char letter_char[8] = {
        2, 5, 10, 13, 18, 21, 26, 29
    };
    char number_char[8] = {
        3, 6, 11, 14, 19, 22, 27, 30
    };
    char double_points[8] = {
        1, 4, 9, 12, 17, 20, 25, 28
    };
    char length[8] = {
        0, 8, 16, 24, 7, 15, 23, 31
    };
    int comp = 2;

    for (int i = 0; i < 8; i++) {
        if (pos_str[letter_char[i]] < 'A' || pos_str[letter_char[i]] > 'H')
            error_write(2);
        if (pos_str[double_points[i]] != ':')
            error_write(2);
        if (pos_str[number_char[i]] < '1' || pos_str[number_char[i]] > '9')
            error_write(2);
        if (i < 4 && pos_str[length[i]] != 48 + comp++)
            error_write(2);
        if (i > 3 && pos_str[length[i]] != '\n')
            error_write(2);
    }
}

int pos_to_value(char letter, char number)
{
    char let_list[8] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'
    };
    int value = 0;

    for (int i = 0; i < 8; i++) {
        if (letter == let_list[i])
            value += (i) * 10;
    }
    value += number - 49;
    return (value);
}

void check_content(char *pos_str)
{
    int first = 0;
    int second = 0;

    for (int i = 0; i < 4; i++) {
        first = pos_to_value(pos_str[i * 8 + 2], pos_str[i * 8 + 3]);
        second = pos_to_value(pos_str[i * 8 + 5], pos_str[i * 8 + 6]);
        if (first != second - (i + 1) * 10 && first != second + (i + 1) * 10
        && first != second - i - 1 && first != second + i + 1)
            error_write(2);
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