/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-mathieu.brujan
** File description:
** int_printer
*/

#include "my_printf.h"

char detec_width(char width_flag, char flag, char answer)
{
    if (flag == width_flag)
        return ('1');
    else
        return (answer);
}

char *check_to_answer(char *check)
{
    char *answer = malloc(sizeof(char) * 5);

    for (int i = 0; i < 4; i++)
        answer[i] = '0';
    answer[4] = '\0';
    answer[0] = check[0];
    if (check[1] == '1')
        answer[1] = '1';
    else if (check[5] == '1')
        answer[1] = '2';
    if (check[3] == '1')
        answer[2] = '1';
    else if (check[2] == '1')
        answer[2] = '2';
    if (check[4] == '1')
        answer[3] = '1';
    return (answer);
}

char is_there_zero(char *flag, char *check)
{
    if (check[4] == '1')
        return ('0');
    for (int i = 0; (flag[i] < '1' || flag[i] > '9') && flag[i] != '.' &&
    flag[i] != '\0'; i++)
        if (flag[i] == '0')
            return ('1');
    return ('0');
}

char *width_check(char *flag)
{
    char *width_flags = "#- +.";
    char *check = malloc(sizeof(char) * 7);
    char *answer;

    my_revstr(flag);
    for (int i = 0; i < 6; i++)
        check[i] = '0';
    check[6] = '\0';
    for (int i = 0; flag[i]; i++) {
        for (int j = 0; width_flags[j]; j++)
            check[j] = detec_width(width_flags[j], flag[i], check[j]);
    }
    check[5] = is_there_zero(flag, check);
    answer = check_to_answer(check);
    free(check);
    return (answer);
}

char *neg_int(char *print, int *nb)
{
    int i = 0;

    my_putchar('-');
    my_revstr(print);
    for (i = 0; print[i]; i++);
    print[i - 1] = '\0';
    my_revstr(print);
    *nb += 1;
    return (print);
}