/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-mathieu.brujan
** File description:
** my_ls
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <sys/types.h>
#include <dirent.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <time.h>
#include "my_printf.h"

int my_ls(int ac, char **av);
int file_counter(char *filepath);
short *gid_to_array(int nb_file, char **array_filename);
char **group_owner_to_array(int nb_file, short *array_gid);
char *space_buffer(char *str, int lenmax);
char **size_to_array(int nb_file, char **array_filename);
char **file_owner_to_array(int nb_file, short *array_uid);
short *uid_to_array(int nb_file, char **array_filename);
short *hard_links_to_array(int nb_file, char **array_filename);
char **stat_mode_to_array(int nb_file, char **array_filename);
char **stat_mode_to_typeperm(int nb_file, char **array_statmode);
char **time_to_array(int nb_file, char **array_filename);
char *add_quote(char *str);
char **file_name_to_array(int nb_file, char *filepath);
char **my_arrdup(char **array_filename, int nb_file);
void caps_rrl_gestion(char *filepath);
void caps_rr_gestion(char *filepath);
void caps_rl_gestion(char *filepath);
void caps_r_gestion(char *filepath);
void single_l(char *filename);
void dash_l_reverse(char *filepath);
void dash_l(char *filepath);
void l_flag(char *flags, char *filepath);
void d_flag(char *flags, char *filepath);
void capr_flag(char *flags, char *filepath);
char *transcript(char *perm, char *type);
void no_arguments(void);
void ls_sorter(char *flags, char *filepath);
void simple_reverse(void);
long long total_blocks(int nb_file, char **array_filename);
char *cut_useless_info(char *time_str);

#endif /* !MY_LS_H_ */
