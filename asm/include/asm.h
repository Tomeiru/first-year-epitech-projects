/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "op.h"

typedef struct info_s {
    char ***files;
    char **filenames;
    int return_value;
    int nb_files;
} info_t;

int write_header(char **file_array, int cor_file);
void write_magic_number(int cor_file);
int write_name(char **file_array, int cor_file);
int write_prog_size(char **file_array, int cor_file, int name_line);
void write_comment(char **file_array, int cor_file, int comment_line);

void asm_file(info_t *info, int i);
void create_cor_file(char **file_array, char *filename);
int error_check_file(char **files);
char *filename_to_filename_cor(char *filename);

int asm_corewar(int ac, char **av);
info_t *fill_info_struct(int ac, char **av);

int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char **str_to_array(char *files);

#endif /* !ASM_H_ */
