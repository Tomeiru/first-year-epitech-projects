/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** string_creators
*/

#include "my_ls.h"

char *stat_mode_to_str(char *filename)
{
    struct stat stats;
    stat(filename, &stats);
    char *stat_mode = print_o(stats.st_mode);

    return (stat_mode);
}

short get_hard_link(char *filename)
{
    struct stat stats;
    stat(filename, &stats);
    short hard_link = stats.st_nlink;

    return (hard_link);
}

short get_uid(char *filename)
{
    struct stat stats;
    stat(filename, &stats);
    short uid = stats.st_uid;

    return (uid);
}

short get_gid(char *filename)
{
    struct stat stats;
    stat(filename, &stats);
    short gid = stats.st_gid;

    return (gid);
}

char *file_owner_to_str(short uid)
{
    struct passwd *pw = getpwuid(uid);
    char *file_owner = pw->pw_name;

    return (file_owner);
}