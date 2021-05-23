/*
** EPITECH PROJECT, 2021
** corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "structs.h"
//#include "op.h"

//main.c
int main(int ac, char **av);

//lib_fct.c
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char *str);
int my_getnbr(char const *str);
int my_str_ishexa(char *str);
int my_str_isnum(char *str);

//error_manager.c
int error_manager(int ac, char **av);
int check_args(int ac, char **av);
int *args_counter(int ac, char **av);
int check_cor(char *cor, char *str);

//setup.c & setup_champion.c
int init_arena(info_t *info);
int get_params(char **av, info_t *info);
void init_info(info_t *info);

//flag_errors.c
int flag_errors(int ac, char **av);

//corewar.c
int corewar(char **av, int champ_number);

//instru_one.c
void live(info_t *info,  champion_t *champion);

#endif /* !COREWAR_H_ */
