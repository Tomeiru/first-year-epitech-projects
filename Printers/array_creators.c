/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** array_creators
*/

#include "my_ls.h"

char *cut_useless_info(char *time_str)
{
    char *result = my_strdup(time_str);

    for ( ; *result != ' '; result++);
    result++;
    result[12] = '\0';
    return (result);
}

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

char *transcript(char *perm, char *type)
{
    char *typeperm = malloc(sizeof(char) * 11);
    int j = 1;

    typeperm[0] = type_transcript(type);
    for (int i = 0; i < 3; i++) {
        if (perm[i] == '7' || perm[i] == '4' || perm[i] == '6' || perm[i] == '5')
            typeperm[j++] = 'r';
        else
            typeperm[j++] = '-';
        if (perm[i] == '7' || perm[i] == '2' || perm[i] == '6' || perm[i] == '3')
            typeperm[j++] = 'w';
        else
            typeperm[j++] = '-';
        if (my_getnbr(type) == 17 && i == 2)
            typeperm[j++] = 't';
        else if (perm[i] == '7' || perm[i] == '1' || perm[i] == '3' || perm[i] == '5')
            typeperm[j++] = 'x';
        else
            typeperm[j++] = '-';
    }
    typeperm[j] = '\0';
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