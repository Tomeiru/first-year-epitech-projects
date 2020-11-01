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

void check_all_digits(char const *expr, char const *base, char const *ops)
{
    int j = 0;
    int k = 0;

    for (int i = 0; expr[i]; i++) {
        for (j = 0; expr[i] != ops[j] && ops[j] != '\0'; j++);
        for (k = 0; expr[i] != base[k] && base[k] != '\0'; k++);
        if (ops[j] == '\0' && base[k] == '\0') {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
    }
}

void check_other_bases(char const *base)
{
    for (int i = 0; base[i]; i++) {
        if (base[i] != i + 48) {
            my_putstr(SYNTAX_ERROR_MSG);
            exit(EXIT_BASE);
        }
    }
}

void main_error_second(char **av, char *expr)
{
    check_all_digits(expr, av[1], av[2]);
    check_other_bases(av[1]);
}