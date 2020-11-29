/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** caps_r_gestion
*/

#include "my_ls.h"

char *filepath_creator(char *filepath, char *folder)
{
    char *new_filepath = malloc(sizeof(char) * (my_strlen(filepath) + my_strlen(folder) + 2));
    int i = 0;
    int j = 0;

    for ( ; i < my_strlen(filepath); i++)
        new_filepath[i] = filepath[i];
    if (filepath[i - 1] != '/')
        new_filepath[i++] = '/';
    for ( ; j < my_strlen(folder); j++)
        new_filepath[i + j] = folder[j];
    new_filepath[i + j] = '\0';
    return (new_filepath);
}

char **file_path_to_arr(int nb_file, char *filepath, char **array_filename)
{
    char **filepath_array;

    if (my_strcmp(filepath, ".") == 0)
        return (array_filename);
    filepath_array = malloc(sizeof(char *) * (nb_file));
    for (int i = 0; i < nb_file; i++)
        filepath_array[i] = filepath_creator(filepath, array_filename[i]);
    return (filepath_array);
}

long long total_blocks(int nb_file, char **array_filename)
{
    struct stat stats;
    long long total = 0;

    for (int i = 0; i < nb_file; i++) {
        stat(array_filename[i], &stats);
        total += stats.st_blocks;
    }
    total /= 2;
    return (total);
}

void caps_rl_gestion(char *filepath)
{
    int nb_file = file_counter(filepath);
    char **array_filename = file_name_to_array(nb_file, filepath);
    char **array_filepath = file_path_to_arr(nb_file, filepath, array_filename);
    char **array_statmode = stat_mode_to_array(nb_file, array_filepath);
    char **array_typeperm = stat_mode_to_typeperm(nb_file, array_statmode);

    my_printf("%s:\n", (filepath));
    dash_l(filepath);
    for (int i = 0; i < nb_file; i++) {
        if (array_typeperm[i][0] == 'd') {
            my_printf("\n");
            caps_rl_gestion(filepath_creator(filepath, array_filename[i]));
        }
    }
}