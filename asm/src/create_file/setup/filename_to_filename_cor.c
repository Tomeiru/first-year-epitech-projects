/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** filename_to_filename_cor
*/

#include "asm.h"

static int get_nb_slash(char *filename)
{
    int ret = 0;

    for (int i = 0; filename[i]; i++)
        if (filename[i] == '/')
            ret++;
    return (ret);
}

static int get_fn_size(char *filename)
{
    int ret = 0;
    int nb_slash = get_nb_slash(filename);

    while (nb_slash != 0) {
        if (*filename == '/')
            nb_slash--;
        filename++;
    }for (int i = 0; filename[i]; i++) {
        if (filename[i] == '.')
            break;
        ret++;
    }
    return (ret);
}

char *filename_to_filename_cor(char *filename)
{
    char *filename_cor = malloc(sizeof(char) * (get_fn_size(filename) + 5));
    int idx = 0;
    int nb_slash = get_nb_slash(filename);

    while (nb_slash != 0) {
        if (*filename == '/')
            nb_slash--;
        filename++;
    }for ( ; filename[idx]; idx++) {
        if (filename[idx] == '.')
            break;
        filename_cor[idx] = filename[idx];
    }filename_cor[idx++] = '.';
    filename_cor[idx++] = 'c';
    filename_cor[idx++] = 'o';
    filename_cor[idx++] = 'r';
    return (filename_cor);
}