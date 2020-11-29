/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** caps_rr_gestion
*/

#include "my_ls.h"

void caps_rr_gestion(char *filepath)
{
    int nb_file = file_counter(filepath);
    char **array_filename = file_name_to_array(nb_file, filepath);
    char **array_filepath = file_path_to_arr(nb_file, filepath, array_filename);
    char **array_statmode = stat_mode_to_array(nb_file, array_filepath);
    char **array_typeperm = stat_mode_to_typeperm(nb_file, array_statmode);

    my_printf("%s:\n", (filepath));
    for (int i = nb_file - 1; i >= 0; i--) {
        if (i - 1 != -1)
            my_printf("%s  ", add_quote(array_filename[i]));
        else
            my_printf("%s\n", add_quote(array_filename[i]));
    }
    for (int i = nb_file - 1; i >= 0; i--) {
        if (array_typeperm[i][0] == 'd') {
            my_printf("\n");
            caps_rr_gestion(filepath_creator(filepath, array_filename[i]));
        }
    }
}