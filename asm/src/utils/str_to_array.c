/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** str_to_array
*/

#include "asm.h"

static int how_many_lines(char *files)
{
    int ret = 1;

    for (int i = 0; files[i]; i++)
        if (files[i] == '\n')
            ret++;
    return (ret);
}

static int get_size_str(char *files, int i)
{
    int ret = 0;

    for ( ; files[i] != '\0' && files[i] != '\n'; i++)
        ret++;
    return (ret);
}

char **str_to_array(char *files)
{
    int size = how_many_lines(files);
    char **array = malloc(sizeof(char *) * (size + 1));
    int j = 0;
    int idx = 0;

    array[0] = malloc(sizeof(char) * (get_size_str(files, 0) + 1));
    for (int i = 0; files[i]; i++) {
        if (files[i] == '\n' || files[i] == '\0') {
            array[j][idx] = '\0';
            idx = 0;
            array[++j] = malloc(sizeof(char) * (get_size_str(files, i+1) + 1));
            continue;
        }array[j][idx++] = files[i];
    }array[j][idx] = '\0';
    array[size] = NULL;
    return (array);
}