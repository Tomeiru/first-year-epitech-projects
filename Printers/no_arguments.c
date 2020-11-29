/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** no_arguments
*/

#include "my_ls.h"

void no_arguments(char *filepath)
{
    int nb_file = file_counter(filepath);
    char **array_filename = file_name_to_array(nb_file, filepath);

    for (int i = 0; i < nb_file; i++) {
        if (i + 1 != nb_file)
            my_printf("%s  ", add_quote(array_filename[i]));
        else
            my_printf("%s\n", add_quote(array_filename[i]));
    }
}

void simple_reverse(void)
{
    int nb_file = file_counter(".");
    char *filepath = ".";
    char **array_filename = file_name_to_array(nb_file, filepath);

    for (int i = nb_file - 1; i >= 0; i--) {
        if (i - 1 != -1)
            my_printf("%s  ", add_quote(array_filename[i]));
        else
            my_printf("%s\n", add_quote(array_filename[i]));
    }
}