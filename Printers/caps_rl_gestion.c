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
    new_filepath[i++] = '/';
    for ( ; j < my_strlen(folder); j++)
        new_filepath[i + j] = folder[j];
    new_filepath[i + j] = '\0';
    return (new_filepath);
}

char **file_path_to_array(int nb_file, char *filepath, char **array_filename)
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
    char **array_filepath = file_path_to_array(nb_file, filepath, array_filename);
    char **array_statmode = stat_mode_to_array(nb_file, array_filepath);
    char **array_typeperm = stat_mode_to_typeperm(nb_file, array_statmode);
    short *array_hardlinks = hard_links_to_array(nb_file, array_filepath);
    short *array_uid = uid_to_array(nb_file, array_filepath);
    short *array_gid = gid_to_array(nb_file, array_filepath);
    char **array_fileowner = file_owner_to_array(nb_file, array_uid);
    char **array_groupowner = group_owner_to_array(nb_file, array_gid);
    char **array_size = size_to_array(nb_file, array_filepath);
    char **array_time = time_to_array(nb_file, array_filepath);
    long long total = total_blocks(nb_file, array_filepath);

    my_printf("%s:\n", filepath);
    my_printf("total %lli\n", total);
    for (int i = 0; i < nb_file; i++) {
        my_printf("%s. ", array_typeperm[i]);
        my_printf("%hi ", array_hardlinks[i]);
        my_printf("%s ", array_fileowner[i]);
        my_printf("%s ", array_groupowner[i]);
        my_printf("%s ", array_size[i]);
        my_printf("%s ", array_time[i]);
        my_printf("%s\n", add_quote(array_filename[i]));
    }
    for (int i = 0; i < nb_file; i++) {
        if (array_typeperm[i][0] == 'd') {
            my_printf("\n");
            caps_rl_gestion(filepath_creator(filepath, array_filename[i]));
        }
    }
}

void caps_r_gestion(char *filepath)
{
    int nb_file = file_counter(filepath);
    char **array_filename = file_name_to_array(nb_file, filepath);
    char **array_filepath = file_path_to_array(nb_file, filepath, array_filename);
    char **array_statmode = stat_mode_to_array(nb_file, array_filepath);
    char **array_typeperm = stat_mode_to_typeperm(nb_file, array_statmode);

    my_printf("%s:\n", filepath);
    for (int i = 0; i < nb_file; i++) {
        if (i + 1 != nb_file)
            my_printf("%s  ", add_quote(array_filename[i]));
        else
            my_printf("%s\n", add_quote(array_filename[i]));
    }
    for (int i = 0; i < nb_file; i++) {
        if (array_typeperm[i][0] == 'd') {
            my_printf("\n");
            caps_r_gestion(filepath_creator(filepath, array_filename[i]));
        }
    }
}

void caps_rrl_gestion(char *filepath)
{
    int nb_file = file_counter(filepath);
    char **array_filename = file_name_to_array(nb_file, filepath);
    char **array_filepath = file_path_to_array(nb_file, filepath, array_filename);
    char **array_statmode = stat_mode_to_array(nb_file, array_filepath);
    char **array_typeperm = stat_mode_to_typeperm(nb_file, array_statmode);
    short *array_hardlinks = hard_links_to_array(nb_file, array_filepath);
    short *array_uid = uid_to_array(nb_file, array_filepath);
    short *array_gid = gid_to_array(nb_file, array_filepath);
    char **array_fileowner = file_owner_to_array(nb_file, array_uid);
    char **array_groupowner = group_owner_to_array(nb_file, array_gid);
    char **array_size = size_to_array(nb_file, array_filepath);
    char **array_time = time_to_array(nb_file, array_filepath);
    long long total = total_blocks(nb_file, array_filepath);

    my_printf("%s:\n", filepath);
    my_printf("total %lli\n", total);
    for (int i = nb_file - 1; i >= 0; i--) {
        my_printf("%s. ", array_typeperm[i]);
        my_printf("%hi ", array_hardlinks[i]);
        my_printf("%s ", array_fileowner[i]);
        my_printf("%s ", array_groupowner[i]);
        my_printf("%s ", array_size[i]);
        my_printf("%s ", array_time[i]);
        my_printf("%s\n", add_quote(array_filename[i]));
    }
    for (int i = nb_file - 1; i >= 0; i--) {
        if (array_typeperm[i][0] == 'd') {
            my_printf("\n");
            caps_rrl_gestion(filepath_creator(filepath, array_filename[i]));
        }
    }
}

void caps_rr_gestion(char *filepath)
{
    int nb_file = file_counter(filepath);
    char **array_filename = file_name_to_array(nb_file, filepath);
    char **array_filepath = file_path_to_array(nb_file, filepath, array_filename);
    char **array_statmode = stat_mode_to_array(nb_file, array_filepath);
    char **array_typeperm = stat_mode_to_typeperm(nb_file, array_statmode);

    my_printf("%s:\n", filepath);
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