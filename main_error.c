/*
** EPITECH PROJECT, 2020
** main_error
** File description:
** main_error
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "include/bistromatic.h"

static void check_para(char const *expr, char const *ops)
{
    int para_count = 0;

    for (int i = 0; expr[i]; i++) {
        if (expr[i] == ops[0])
            para_count += 1;
        if (expr[i] == ops[1])
            para_count -= 1;
        if (para_count < 0) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_PARA);
        }
    }
    if (para_count != 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_PARA);
    }
}

static void check_ops(char const *ops)
{
    int i = 0;
    int j = 0;

    if (my_strlen(ops) != 7) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    for (i = 0; ops[i]; i++) {
        for (j = i + 1; ops[j] != ops[i] && ops[j] != '\0'; j++);
        if (ops[j] != '\0')
            break;
    }
    if (ops[i] != '\0') {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
}

static void check_base(char const *b)
{
    int i = 0;
    int j = 0;

    if (my_strlen(b) < 2) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    for (i = 0; b[i]; i++) {
        for (j = i + 1; b[j] != b[i] && b[j] != '\0'; j++);
        if (b[j] != '\0')
            break;
    }
    if (b[i] != '\0') {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}

static void check_baseops(char const *b, char const *ops)
{
    int i = 0;
    int j = 0;

    for (i = 0; ops[i]; i++) {
        for (j = i; b[j] != ops[i] && b[j] != '\0'; j++);
        if (b[j] != '\0')
            break;
    }
    if (ops[i] != '\0') {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
}


void main_error(int ac, char **av, char *expr)
{
    check_base(av[1]);
    check_ops(av[2]);
    check_baseops(av[1], av[2]);
    check_para(expr, av[2]);
}
