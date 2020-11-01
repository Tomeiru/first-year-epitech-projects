/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function for bistro
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "include/bistromatic.h"

int help(void)
{
    my_putstr("USAGE\n./calc base operators size_read\n\nDESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n- operators: the symbols ");
    my_putstr("for the parentheses and the 5 operators\n- size_read: number ");
    my_putstr("of characters to be read\n");
    return (EXIT_SUCCESS);
}

static char *get_expr(unsigned int size)
{
    char *expr;

    if (size <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    }
    expr = malloc(sizeof(char) * (size + 1));
    if (expr == 0) {
        my_putstr(ERROR_MSG);
        exit(EXIT_MALLOC);
    }
    if (read(0, expr, size) != size) {
        my_putstr(ERROR_MSG);
        exit(EXIT_READ);
    }
    expr[size] = 0;
    return (expr);
}

int main(int ac, char **av)
{
    unsigned int size = my_atoi(av[3]);
    char *expr;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        return (help());
    }
    expr = get_expr(size);
    main_error(av, expr);
    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (EXIT_USAGE);
    }
    my_putstr(eval_expr(av[2], expr, size));
    return (EXIT_SUCCESS);
}