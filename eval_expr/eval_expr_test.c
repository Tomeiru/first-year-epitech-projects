/*
** EPITECH PROJECT, 2020
** sumfac
** File description:
** takes care of add, sub, mul, div and modulo
*/
#include <stdlib.h>
#include "include/bistromatic.h"

char *my_strtol(char *str, char **endptr, char *ops)
{
    char *res = malloc(10000);
    int i = 0;
    int j = 0;

    if (str[i] == ops[3]) {
        res[j++] = '-';
        i++;
    }
    else if (str[i] == '+' || str[i] == ops[4] || str[i] == ops[5] ||
    str[i] == ops[6])
        i++;
    for ( ; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            res[j++] = str[i];
        else if (str[i] < '0' || str[i] > '9')
            break;
    }
    *endptr = &str[i];
    return (res);
}

char *parentheses(char *str, char **endptr, char *ops, int size)
{
    char *res = my_strtol(str, endptr, ops);

    if ((str[0] == ops[2] || str[0] == ops[3] || str[0] == ops[4] ||
    str[0] == ops[5] || str[0] == ops[6]) && (str[1] == ops[0]))
        str++;
    if (*str == ops[0]) {
        str++;
        res = summands(&str, ops, size);
        *endptr = str;
        if (**endptr == ')')
            *endptr += 1;
    }
    return (res);
}

char *factors(char *str, char **endptr, char *ops, int size)
{
    char *res = parentheses(str, endptr, ops, size);

    while (**endptr == ops[4] || **endptr == ops[5] || **endptr == ops[6]) {
        if (**endptr == ops[4])
            res = infin_mul(res, parentheses(*endptr, endptr, ops, size));
        else if (**endptr == ops[5])
            res = infin_div(res, parentheses(*endptr, endptr, ops, size));
        else
            res = infin_mod(res, parentheses(*endptr, endptr, ops, size));
    }
    return (res);
}

char *summands(char **str_ptr, char *ops, int size)
{
    char *endptr = "test";
    char *res = factors(*str_ptr, &endptr, ops, size);

    while (*endptr == ops[2] || *endptr == ops[3])
        res = infin_add(res, factors(endptr, &endptr, ops, size));
    *str_ptr = endptr;
    return (res);
}

char *eval_expr(char *base, char *ops, char *expr, int size)
{
    expr = "3+5*2";
    if (error(expr) == 1)
        return (summands(&expr, ops, size));
    return ("Error");
}