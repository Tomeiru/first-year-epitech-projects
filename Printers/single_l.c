/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** single_l
*/

#include "my_ls.h"

char *stat_mode_to_str(char *filename)
{
    struct stat stats;
    int stat_value = stat(filename, &stats);
    char *stat_mode = print_o(stats.st_mode);

    return (stat_mode);
}

short get_hard_link(char *filename)
{
    struct stat stats;
    int stat_value = stat(filename, &stats);
    short hard_link = stats.st_nlink;

    return (hard_link);
}

short get_uid(char *filename)
{
    struct stat stats;
    int stat_value = stat(filename, &stats);
    short uid = stats.st_uid;

    return (uid);
}

short get_gid(char *filename)
{
    struct stat stats;
    int stat_value = stat(filename, &stats);
    short gid = stats.st_gid;

    return (gid);
}

char *file_owner_to_str(short uid)
{
    struct passwd *pw = getpwuid(uid);
    char *file_owner = pw->pw_name;

    return (file_owner);
}

char *group_owner_to_str(short gid)
{
    struct group *gp = getgrgid(gid);
    char *group_owner = gp->gr_name;

    return (group_owner);
}

char *size_to_str(char *filename)
{
    struct stat stats;
    int stat_value = stat(filename, &stats);
    char *size = print_di(stats.st_size);

    return (size);
}

char *time_to_str(char *filename)
{
    struct stat stats;
    int stat_value = stat(filename, &stats);
    char *time = cut_useless_info(ctime(&stats.st_ctime));

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

void single_l(char *filename)
{
    char *statmode = stat_mode_to_str(filename);
    char *typeperm = stat_mode_to_typeperm_str(statmode);
    short hardlinks = get_hard_link(filename);
    short uid = get_uid(filename);
    short gid = get_gid(filename);
    char *fileowner = file_owner_to_str(uid);
    char *groupowner = group_owner_to_str(gid);
    char *size = size_to_str(filename);
    char *time = time_to_str(filename);

    my_printf("%s. ", typeperm);
    my_printf("%hi ", hardlinks);
    my_printf("%s ", fileowner);
    my_printf("%s ", groupowner);
    my_printf("%s ", size);
    my_printf("%s ", time);
    my_printf("%s\n", filename);
}