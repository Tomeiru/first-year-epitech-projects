/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** array_creators_second
*/

#include "my_ls.h"

int file_counter(char *filepath)
{
    DIR *dir = opendir(filepath);
    struct dirent *file = readdir(dir);
    int file_count = 0;

    while (file != NULL) {
        if (file->d_name[0] != '.')
            file_count++;
        file = readdir(dir);
    }
    closedir(dir);
    return (file_count);
}

char **stat_mode_to_array(int nb_file, char **array_filename)
{
    struct stat stats;
    char *stat_mode[nb_file];

    for (int i = 0; i < nb_file; i++) {
        stat(array_filename[i], &stats);
        stat_mode[i] = print_o(stats.st_mode);
    }
    return (my_arrdup(stat_mode, nb_file));
}

short *hard_links_to_array(int nb_file, char **array_filename)
{
    struct stat stats;
    short *hard_links = malloc(sizeof(short) * nb_file);

    for (int i = 0; i < nb_file; i++) {
        stat(array_filename[i], &stats);
        hard_links[i] = stats.st_nlink;
    }
    return (hard_links);
}

short *uid_to_array(int nb_file, char **array_filename)
{
    struct stat stats;
    short *uid = malloc(sizeof(short) * nb_file);

    for (int i = 0; i < nb_file; i++) {
        stat(array_filename[i], &stats);
        uid[i] = stats.st_uid;
    }
    return (uid);
}

short *gid_to_array(int nb_file, char **array_filename)
{
    struct stat stats;
    short *gid = malloc(sizeof(short) * nb_file);

    for (int i = 0; i < nb_file; i++) {
        stat(array_filename[i], &stats);
        gid[i] = stats.st_gid;
    }
    return (gid);
}