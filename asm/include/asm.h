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

#define UNUSED(var) (void)(var)
#define MAX_ARGS_NUMBER 4
#define T_REG 1
#define T_DIR 2
#define T_IND 4
#define T_LAB 8

typedef char args_type_t;

typedef struct op_s
{
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;

extern op_t op_tab[];

typedef struct info_s {
    char ***files;
    char **filenames;
    int return_value;
    int nb_files;
} info_t;

int get_info_label(char *line);
char *get_arg_str(char *line, int label, int idx);
char *get_command_str(char *line, int label);
char **get_args_arr(char *line, int label);
unsigned char get_coding_byte(char **args);

int get_command_value(char *line);
void write_command(char *line, int cor_file, int command);
void write_body(char **file_array, int cor_file, int body_line);

unsigned int get_direct_value(char *arg);
unsigned short get_indirect_value(char *arg);
unsigned short get_index_value(char *arg);
void write_live(char *line, int cor_file);
void write_ld(char *line, int cor_file);
void write_st(char *line, int cor_file);
void write_add(char *line, int cor_file);
void write_sub(char *line, int cor_file);
void write_and(char *line, int cor_file);
void write_and_eight(int cor_file, unsigned char coding_byte,
char **args);
void write_and_nine(int cor_file, unsigned char coding_byte,
char **args);
void write_and_eleven(int cor_file, unsigned char coding_byte,
char **args);
void write_or(char *line, int cor_file);
void write_or_eight(int cor_file, unsigned char coding_byte,
char **args);
void write_or_nine(int cor_file, unsigned char coding_byte,
char **args);
void write_or_eleven(int cor_file, unsigned char coding_byte,
char **args);
void write_xor(char *line, int cor_file);
void write_xor_eight(int cor_file, unsigned char coding_byte,
char **args);
void write_xor_nine(int cor_file, unsigned char coding_byte,
char **args);
void write_xor_eleven(int cor_file, unsigned char coding_byte,
char **args);
void write_zjmp(char *line, int cor_file);
void write_ldi(char *line, int cor_file);
void write_ldi_six(char *line, int cor_file);
void write_sti(char *line, int cor_file);
void write_fork(char *line, int cor_file);
void write_lld(char *line, int cor_file);
void write_lldi(char *line, int cor_file);
void write_lldi_six(char *line, int cor_file);
void write_lfork(char *line, int cor_file);
void write_aff(char *line, int cor_file);

unsigned int size_five(char *line);
unsigned int size_ld_lld(char *line);
unsigned int size_ldi_lldi(char *line);
unsigned int size_st(char *line);
unsigned int size_and_or_xor(char *line);
unsigned int size_three(char *line);
unsigned int size_seven(char *line);
unsigned int size_sti(char *line);

int write_header(char **file_array, int cor_file);
void write_magic_number(int cor_file);
int write_name(char **file_array, int cor_file);
int write_prog_size(char **file_array, int cor_file, int name_line);
unsigned long long get_prog_size(char **file_array, int body_line);
void write_comment(char **file_array, int cor_file, int comment_line);

int check_comment_presence(char **file_array, int after_name_line);
int error_comment(char **file_array, int line_name);
int check_error_code_comment(int error_code);
int check_syntax_comment(char **file_array, int comment_presence);

int check_error_code_name(int error_code);
int check_name_presence(char **file_array);
int check_syntax_name(char **file_array, int name_presence);
int error_name(char **file_array);

int check_direct_arg(char *arg);
int check_indirect_arg(char *arg);
int check_label_arg(char *arg);
int check_register_arg(char *arg);
int count_arg(char **arg);

int check_args_aff(char *line);
int check_args_add_sub(char *line);
int check_args_and_or_xor(char *line);
int check_args_ld_lld(char *line);
int check_args_ldi_lldi(char *line);
int check_args_live_zjmp_fork_lfork(char *line);
int check_args_st(char *line);
int check_args_sti(char *line);

int check_args_line(char *line, int command);
int check_args_prog(char **file_array, int after_comment_line,
int status_command);
int check_error_code_args(int status);

int check_command_prog(char **file_array, int after_comment_line);
int error_prog(char **file_array, int comment_line);

int check_after_quotes(char *line_name);
int error_check_file(char **files);

void asm_file(info_t *info, int i);
void create_cor_file(char **file_array, char *filename);
char *filename_to_filename_cor(char *filename);

int asm_corewar(int ac, char **av);
info_t *fill_info_struct(int ac, char **av);

int my_getnbr(char const *str);
void my_put_nbr(int nb);
void my_putchar(char c);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char **str_to_array(char *files);

#endif /* !ASM_H_ */
