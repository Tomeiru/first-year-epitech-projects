/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** flag
*/

#include "my_printf.h"

static int flag_condition(char c)
{
    char *allowed_c = "#0123456789 +-hljztqZ";

    for (int i = 0; allowed_c[i]; i++) {
        if (allowed_c[i] == c)
            return (1);
    }
    return (0);
}

static char *flag_checker(char *flag)
{
    int number = 0;
    int i = 0;

    flag = my_revstr(flag);
    if (number == 1) {
        for (i = 1; flag_condition(flag[i]) == 1 && flag[i] != '\0'; i++);
        if (flag[i] != '\0')
            return ("e");
    }
    return (my_revstr(flag));
}

char *flag_finder(char *format)
{
    char *conv_spe = "diouxXbcsSp%";
    char *result = my_strdup(format);
    int i = 0;

    for (int j = 0; conv_spe[j]; j++) {
        if (conv_spe[j] == format[i]) {
            result[i + 1] = '\0';
            result = flag_checker(result);
            return (result);
            }
        if (j == 11) {
            i++;
            j = -1;
        }
    }
    return ("0");
}