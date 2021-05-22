/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_name
*/

#include "asm.h"

static int get_name_line(char **file_array)
{
    int i = 0;
    int j = 0;

    for ( ; file_array[i]; i++) {
        for ( ; file_array[i][j] == ' ' || file_array[i][j] == 9; j++);
        if (file_array[i][j] == '#')
            continue;
        if (file_array[i][j] == '.')
            return (i);
    }return (-1);
}

int write_name(char **file_array, int cor_file)
{
    int idx = get_name_line(file_array);
    char name[128];
    int i = 0;
    int j = 0;

    for ( ; file_array[idx][i] != '"'; i++);
    i++;
    for ( ; file_array[idx][i] != '"'; i++)
        name[j++] = file_array[idx][i];
    for ( ; j < 128; j++)
        name[j] = 0;
    write(cor_file, name, 128);
    return (idx);
}