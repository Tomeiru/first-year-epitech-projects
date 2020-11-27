/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** need_sort
*/

#include "my_ls.h"

char **my_arrdup(char **array_filename, int nb_file)
{
    char **cpy = malloc(sizeof(char *) * nb_file);

    for (int i = 0; i < nb_file; i++)
        cpy[i] = my_strdup(array_filename[i]);
    return (cpy);
}

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
        time[i] = ctime(&stats.st_ctime);
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

void dash_l(char *filepath)
{
    int nb_file = file_counter(filepath);
    char **array_filename = file_name_to_array(nb_file, filepath);
    char **array_statmode = stat_mode_to_array(nb_file, array_filename);
    char **array_typeperm = stat_mode_to_typeperm(nb_file, array_statmode);
    short *array_hardlinks = hard_links_to_array(nb_file, array_filename);
    short *array_uid = uid_to_array(nb_file, array_filename);
    short *array_gid = gid_to_array(nb_file, array_filename);
    char **array_fileowner = file_owner_to_array(nb_file, array_uid);
    char **array_groupowner = group_owner_to_array(nb_file, array_gid);
    char **array_size = size_to_array(nb_file, array_filename);
    char **array_time = time_to_array(nb_file, array_filename);
    long long total = total_blocks(nb_file, array_filename);

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
}

void dash_l_reverse(char *filepath)
{
    int nb_file = file_counter(filepath);
    char **array_filename = file_name_to_array(nb_file, filepath);
    char **array_statmode = stat_mode_to_array(nb_file, array_filename);
    char **array_typeperm = stat_mode_to_typeperm(nb_file, array_statmode);
    short *array_hardlinks = hard_links_to_array(nb_file, array_filename);
    short *array_uid = uid_to_array(nb_file, array_filename);
    short *array_gid = gid_to_array(nb_file, array_filename);
    char **array_fileowner = file_owner_to_array(nb_file, array_uid);
    char **array_groupowner = group_owner_to_array(nb_file, array_gid);
    char **array_size = size_to_array(nb_file, array_filename);
    char **array_time = time_to_array(nb_file, array_filename);
    long long total = total_blocks(nb_file, array_filename);

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
}