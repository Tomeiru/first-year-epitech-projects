/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** single_l
*/

#include "my_ls.h"

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

    my_printf("%s ", typeperm);
    my_printf("%hi ", hardlinks);
    my_printf("%s ", fileowner);
    my_printf("%s ", groupowner);
    my_printf("%s ", size);
    my_printf("%s ", time);
    my_printf("%s\n", filename);
}