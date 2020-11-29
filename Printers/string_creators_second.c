/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** string_creators_second
*/

#include "my_ls.h"

char *group_owner_to_str(short gid)
{
    struct group *gp = getgrgid(gid);
    char *group_owner = gp->gr_name;

    return (group_owner);
}

char *size_to_str(char *filename)
{
    struct stat stats;
    stat(filename, &stats);
    char *size = print_di(stats.st_size);

    return (size);
}

char *time_to_str(char *filename)
{
    struct stat stats;
    stat(filename, &stats);
    char *time = cut_useless_info(ctime(&stats.st_mtime));

    return (time);
}

char *stat_mode_to_typeperm_str(char *statmode)
{
    char *typeperm;
    char *perm;
    char *type;

    type = my_strdup(statmode);
    type = my_revstr(type);
    type += 4;
    type = my_revstr(type);
    perm = my_strdup(statmode);
    perm = my_revstr(perm);
    perm[3] = '\0';
    perm = my_revstr(perm);
    typeperm = transcript(perm, type);
    return (typeperm);
}

char *cut_useless_info(char *time_str)
{
    char *result = my_strdup(time_str);

    for ( ; *result != ' '; result++);
    result++;
    result[12] = '\0';
    return (result);
}