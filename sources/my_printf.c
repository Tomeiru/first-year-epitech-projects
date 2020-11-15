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
    char *conv_spe = "dicouxXbpsS%";
    int i = 0;

    for ( ; i < 3; i++)
        if (conv_spe[i] == c)
            return (0);
    for ( ; i < 9; i++)
        if (conv_spe[i] == c)
            return (1);
    for ( ; i < 11; i++)
        if (conv_spe[i] == c)
            return (2);
    if (conv_spe[11] == c)
        return (3);
    return (0);
}

void my_printf(char *format, ...)
{
    int counter = 0;
    char *flag;
    va_list list;

    for (int i = 0; format[i]; i++)
        if (format[i] == '%')
            counter++;
    va_start(list, format);
    for (int i = 0; i < counter; i++) {
        format = normal_print(format);
        flag = my_strdup(flag_finder(format));
        if (flag[0] != 'e') {
            format += my_strlen(flag);
            type_sort(flag, list, &counter);
        }
        else
            my_putchar('%');
    }
    my_putstr(format);
}