/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** array_creators_third
*/

#include "my_ls.h"

char **my_arrdup(char **array_filename, int nb_file)
{
    char **cpy = malloc(sizeof(char *) * nb_file);

    for (int i = 0; i < nb_file; i++)
        cpy[i] = my_strdup(array_filename[i]);
    return (cpy);
}

char **file_owner_to_array(int nb_file, short *array_uid)
{
    struct passwd *pw;
    char *file_owner[nb_file];

    for (int i = 0; i < nb_file; i++) {
        pw = getpwuid(array_uid[i]);
        file_owner[i] = pw->pw_name;
    }
    return (my_arrdup(file_owner, nb_file));
}

char **group_owner_to_array(int nb_file, short *array_gid)
{
    struct group *gp;
    char *group_owner[nb_file];

    for (int i = 0; i < nb_file; i++) {
        gp = getgrgid(array_gid[i]);
        group_owner[i] = gp->gr_name;
    }
    return (my_arrdup(group_owner, nb_file));
}

char *space_buffer(char *str, int lenmax)
{
    char *new_str = malloc(sizeof(char) * (lenmax + 1));
    int i = 0;
    int j = 0;

    for ( ; i < lenmax - my_strlen(str); i++)
        new_str[i] = ' ';
    for ( ; i + j < lenmax; j++)
        new_str[i + j] = str[j];
    new_str[i + j] = '\0';
    return (new_str);
}

char **size_to_array(int nb_file, char **array_filename)
{
    struct stat stats;
    char **size = malloc(sizeof(char *) * (nb_file));

    for (int i = 0; i < nb_file; i++) {
        stat(array_filename[i], &stats);
        size[i] = print_di(stats.st_size);
    }
    return (size);
}