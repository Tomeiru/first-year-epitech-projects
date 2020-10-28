/*
** EPITECH PROJECT, 2020
** Result
** File description:
** eval_expr
*/

#ifndef EVAL_EXPR_H_
#define EVAL_EXPR_H_

#include <stdlib.h>
#include "my.h"

int add_counter(char const *str);
int fac_counter(char const *str);
int main(int ac, char **av);
int mix(char const *str);
int multi_fac(char const *str, int count);
void my_strtolfac(char const *str, char **endptr);
int my_strtol(char const *str, char **endptr);
int my_strsign(char const *str);
int assign_value(char const *str, char **endptr);
int error(char const *str);

#endif /* !EVAL_EXPR_H_ */
