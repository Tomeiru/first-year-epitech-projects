/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** array_creators
*/

#include "my_ls.h"

char **time_to_array(int nb_file, char **array_filename)
{
    struct stat stats;
    char *time[nb_file];

    for (int i = 0; i < nb_file; i++) {
        stat(array_filename[i], &stats);
        time[i] = ctime(&stats.st_mtime);
        time[i] = cut_useless_info(time[i]);
    }
    return (my_arrdup(time, nb_file));
}

char type_transcript(char *type)
{
    int type_nbr = my_getnbr(type);
    int type_list[8] = {
        1, 2, 4, 6, 10, 12, 14, 17
    };
    char transcripted_type[8] = {
        'p', 'c', 'd', 'b', '-', 'l', 's', 'd'
    };

    for (int i = 0; i < 7; i++)
        if (type_nbr == type_list[i])
            return (transcripted_type[i]);
    return (48);
}

char *perm_selection(char perm, char *typeperm, int j)
{
    if (perm == '7' || perm == '4' || perm == '6' || perm == '5')
        typeperm[j++] = 'r';
    else
        typeperm[j++] = '-';
    if (perm == '7' || perm == '2' || perm == '6' || perm == '3')
        typeperm[j++] = 'w';
    else
        typeperm[j++] = '-';
    if (perm == '7' || perm == '1' || perm == '3' || perm == '5')
        typeperm[j++] = 'x';
    else
        typeperm[j++] = '-';
    return (typeperm);
}

char *transcript(char *perm, char *type)
{
    char *typeperm = malloc(sizeof(char) * 11);
    int j = 1;

    typeperm[0] = type_transcript(type);
    for (int i = 0; i < 3; i++) {
        typeperm = perm_selection(perm[i], typeperm, j);
        j += 3;
    }
    typeperm[10] = '\0';
    if (my_getnbr(type) == 17)
        typeperm[9] = 't';
    return (typeperm);
}

char **stat_mode_to_typeperm(int nb_file, char **array_statmode)
{
    char *typeperm[nb_file];
    char *perm[nb_file];
    char *type[nb_file];

    for (int i = 0; i < nb_file; i++) {
        type[i] = my_strdup(array_statmode[i]);
        type[i] = my_revstr(type[i]);
        type[i] += 4;
        type[i] = my_revstr(type[i]);
        perm[i] = my_strdup(array_statmode[i]);
        perm[i] = my_revstr(perm[i]);
        perm[i][3] = '\0';
        perm[i] = my_revstr(perm[i]);
        typeperm[i] = transcript(perm[i], type[i]);
    }
    return (my_arrdup(typeperm, nb_file));
}