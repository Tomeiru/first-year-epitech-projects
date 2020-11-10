/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** my_printf
*/

#include "my_printf.h"

char *normal_print(char *format)
{
    for (; *format != '%'; format++)
        my_putchar(*format);
    format++;
    return (format);
}

int which_type(char c)
{
    char *conv_spe = "dicouxXbsSp%";
    int type = 0;
    int i = 0;

    for ( ; i < 3; i++)
        if (conv_spe[i] == c)
            return (0);
    for ( ; i < 8; i++)
        if (conv_spe[i] == c)
            return (1);
    for ( ; i < 10; i++)
        if (conv_spe[i] == c)
            return (2);
    if (conv_spe[10] == c)
        return (3);
    if (conv_spe[11] == c)
        return (4);
}

int my_printf(const char *format, ...)
{
    int counter = 0;
    int type = 0;
    char *flag;
    va_list list;

    for (int i = 0; format[i]; i++)
        if (format[i] == '%' && format[i + 1] != '%')
            counter++;
    if (counter == 0) {
        my_putstr(format);
        return(my_strlen(format));
    }
    va_start(list, format);
    for (int i = 0; i < counter; i++) {
        format = normal_print(format);
        flag = my_strdup(flag_finder(format));
        if (flag[0] != 'e')
            format += my_strlen(flag);
        else
            my_putchar('%');
        type = which_type(my_revstr(flag)[0]);
        if (type == 0)
            arg_int(flag, va_arg(list, long long));
        if (type == 1)
            arg_uns_int(flag, va_arg(list, unsigned long long));
        if (type == 2)
            arg_str(flag, va_arg(list, char *));
        /*if (type == 3)
            arg_ptr(flag, va_arg(list, void *));*/
        if (type == 4)
            my_putchar('%');
    }
    my_putstr(format);
}
