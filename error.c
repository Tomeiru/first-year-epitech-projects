/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** error
*/

#include "titration.h"

void error_file(char *file, int len)
{
    int semi_count = 0;
    int point_count = 0;

    if (file[0] == '.' || file[0] == ';' || file[0] == '\n')
        exit(84);
    for (int i = 0; file[i]; i++) {
        if (!(file[i] == '.' || file[i] == ';' || file[i] == '\n' || (file[i] >= '0' && file[i] <= '9')))
            exit(84);
        if (file[i] == '.')
            point_count++;
        if (file[i] == ';') {
            semi_count++;
            point_count = 0;
        }if (file[i] == '\n') {
            if (semi_count == 1)
                semi_count = 0;
            else
                exit(84);
        }if (semi_count == 2 || point_count == 2)
            exit(84);
    }
}

void error(int ac)
{
    if (ac != 2)
        exit(84);
}