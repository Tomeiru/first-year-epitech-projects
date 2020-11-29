/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** caps_rrl_gestion
*/

#include "my_ls.h"

void caps_rrl_gestion(char *filepath)
{
    int nb_file = file_counter(filepath);
    char **array_filename = file_name_to_array(nb_file, filepath);
    char **array_filepath = file_path_to_arr(nb_file, filepath, array_filename);
    char **array_statmode = stat_mode_to_array(nb_file, array_filepath);
    char **array_typeperm = stat_mode_to_typeperm(nb_file, array_statmode);

    my_printf("%s:\n", slash_cut(filepath));
    dash_l_reverse(filepath);
    for (int i = nb_file - 1; i >= 0; i--) {
        if (array_typeperm[i][0] == 'd') {
            my_printf("\n");
            caps_rrl_gestion(filepath_creator(filepath, array_filename[i]));
        }
    }
}