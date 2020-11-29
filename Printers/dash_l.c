/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** need_sort
*/

#include "my_ls.h"

void dash_l(char *filepath)
{
    int nb_file = file_counter(filepath);
    char **array_filename = file_name_to_array(nb_file, filepath);
    char **array_filepath = file_path_to_arr(nb_file, filepath, array_filename);
    char **array_statmode = stat_mode_to_array(nb_file, array_filepath);
    char **array_typeperm = stat_mode_to_typeperm(nb_file, array_statmode);
    short *array_hardlinks = hard_links_to_array(nb_file, array_filepath);
    short *array_uid = uid_to_array(nb_file, array_filepath);
    short *array_gid = gid_to_array(nb_file, array_filepath);
    char **array_fileowner = file_owner_to_array(nb_file, array_uid);
    char **array_groupowner = group_owner_to_array(nb_file, array_gid);
    char **array_size = size_to_array(nb_file, array_filepath);
    char **array_time = time_to_array(nb_file, array_filepath);

    my_printf("total %lli\n", total_blocks(nb_file, array_filepath));
    for (int i = 0; i < nb_file; i++) {
        my_printf("%s %hi ", array_typeperm[i], array_hardlinks[i]);
        my_printf("%s %s ", array_fileowner[i], array_groupowner[i]);
        my_printf("%s %s ", array_size[i], array_time[i]);
        my_printf("%s\n", add_quote(array_filename[i]));
    }
}

void dash_l_reverse(char *filepath)
{
    int nb_file = file_counter(filepath);
    char **array_filename = file_name_to_array(nb_file, filepath);
    char **array_filepath = file_path_to_arr(nb_file, filepath, array_filename);
    char **array_statmode = stat_mode_to_array(nb_file, array_filepath);
    char **array_typeperm = stat_mode_to_typeperm(nb_file, array_statmode);
    short *array_hardlinks = hard_links_to_array(nb_file, array_filepath);
    short *array_uid = uid_to_array(nb_file, array_filepath);
    short *array_gid = gid_to_array(nb_file, array_filepath);
    char **array_fileowner = file_owner_to_array(nb_file, array_uid);
    char **array_groupowner = group_owner_to_array(nb_file, array_gid);
    char **array_size = size_to_array(nb_file, array_filepath);
    char **array_time = time_to_array(nb_file, array_filepath);

    my_printf("total %lli\n", total_blocks(nb_file, array_filepath));
    for (int i = nb_file - 1; i >= 0; i--) {
        my_printf("%s %hi ", array_typeperm[i], array_hardlinks[i]);
        my_printf("%s %s ", array_fileowner[i], array_groupowner[i]);
        my_printf("%s %s ", array_size[i], array_time[i]);
        my_printf("%s\n", add_quote(array_filename[i]));
    }
}