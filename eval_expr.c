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
    int sign = 1;

    for ( ;str[i] == ops[2] || str[i] == ops[3]; i++) {
        if (str[i] == ops[3])
            sign *= -1;
    }
    if (sign == -1)
        res[j++] = '-';
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

    for ( ; str[0] == ops[3] || str[0] == ops[2]; ++str);
    if ((str[0] == ops[2] || str[0] == ops[3] || str[0] == ops[4] ||
    str[0] == ops[5] || str[0] == ops[6]) && (str[1] == ops[0]))
        str++;
    if (*str == ops[0]) {
        str++;
        if (res[0] == '-' && res[1] == '\0')
            res = minus_adder(summands(&str, ops, size));
        else
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
        if (**endptr == ops[4]) {
            *endptr += 1;
            res = infin_mult(res, parentheses(*endptr, endptr, ops, size));
        }
        else if (**endptr == ops[5]) {
            *endptr += 1;
            res = infin_div(res, parentheses(*endptr, endptr, ops, size));
        }
        else {
            *endptr += 1;
            res = infin_mod(res, parentheses(*endptr, endptr, ops, size));
        }
    }
    return (res);
}

char *summands(char **str_ptr, char *ops, int size)
{
    char *endptr = "test";
    char *res = factors(*str_ptr, &endptr, ops, size);

    while (*endptr == ops[2] || *endptr == ops[3]) {
        if (*endptr == ops[2]) {
            endptr += 1;
            res = infin_add(res, factors(endptr, &endptr, ops, size));
        }
        if (*endptr == ops[3]) {
            endptr += 1;
            res = infin_sub(res, factors(endptr, &endptr, ops, size));
        }
    }
    *str_ptr = endptr;
    return (res);
}

char *eval_expr(char *base, char *ops, char *expr, int size)
{

    char *result = summands(&expr, ops, size);
    char **temp = "test";

    result = my_strtol(result, &temp, ops);
    return (result);
}