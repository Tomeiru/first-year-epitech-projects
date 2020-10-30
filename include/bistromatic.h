/*
** EPITECH PROJECT, 2020
** bistromatic.h
** File description:
** bistromatic.h
*/

#ifndef BISTROMATIC_H
#define BISTROMATIC_H

#define OP_OPEN_PARENT_IDX 0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX 2
#define OP_SUB_IDX 3
#define OP_NEG_IDX 3
#define OP_MULT_IDX 4
#define OP_DIV_IDX 5
#define OP_MOD_IDX 6

#define EXIT_USAGE 84
#define EXIT_BASE 84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC 84
#define EXIT_READ 84
#define EXIT_OPS 84
#define EXIT_EMPTY 84
#define EXIT_PARA 84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG "error"

#include <stdlib.h>
#include "my.h"

char *my_strtol(char *str, char **endptr, char *ops);
char *parentheses(char *str, char **endptr, char *ops, int size);
char *factors(char *str, char **endptr, char *ops, int size);
char *summands(char **str_ptr, char *ops, int size);
char *eval_expr(char *base, char *ops, char *expr, int size);
int my_atoi(char *str);
char *absol(char *num, int sign, int length);
int biggest_number (char *fst_num, char *sec_num, int fst_sign, int sec_sign);
int error_inf (int ac, char **av);
char *infin_add(char *fst_num, char *sec_num);
int is_valid_num(char const *str);
int longest_string(int first, int second, int fst_sign, int sec_sign);
int my_sign(char *num);
char *same_tenth(char *fst_num, char *sec_num, int fst_sign, int sec_sign);
char *stenth_dsign(char *fst_num, char *sec_num, int retenue, int number);
char *stenth_ssign(char *fst_num, char *sec_num, int retenue, int number);
char *zero(char *str, int dif, int len);
char *first_longest(char *fst_num, char *sec_num, int fst_sign, int sec_sign);
char *second_longest(char *fst_num, char *sec_num, int fst_sign, int sec_sign);
char *mult_line(char *fst_abs, int num_line, int value);
char *calc_mult(char *fst_abs, char *sec_abs);
char *minus_adder(char *str);
char *infin_mult(char *fst_num, char *sec_num);
int do_we_div(char *fst_num, char *sec_num);
char *div_calc(char *fst_abs, char *sec_abs);
char *rest(char *total, char *abs, char quotient);
char *div_glob(char *fst_abs, char *sec_abs);
char *infin_div(char *fst_num, char *sec_num);
char *rest(char *total, char *abs, char quotient);
char *mod_glob(char *fst_abs, char *sec_abs);
int do_we_mod(char *fst_num, char *sec_num);
char *infin_mod(char *fst_num, char *sec_num);
char *infin_sub(char *fst_num, char *sec_num);
void div_by_zero(char *num);
void main_error(char **av, char *expr);

#endif /* BISTROMATIC_H_*/