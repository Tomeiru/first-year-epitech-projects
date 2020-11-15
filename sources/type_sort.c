/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** type_sort
*/

#include "my_printf.h"

void type_sort(char *flag, va_list list, int *count)
{
    int type = which_type(my_revstr(flag)[0]);

    if (type == 0)
        arg_int(flag, va_arg(list, long long));
    if (type == 1)
        arg_uns_int(flag, va_arg(list, unsigned long long));
    if (type == 2)
        arg_str(flag, va_arg(list, char *));
    if (type == 3) {
        my_putchar('%');
        *count -= 1;
    }
}