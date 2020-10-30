/*
** EPITECH PROJECT, 2020
** Bistromatic
** File description:
** calc
*/

#include "../../include/bistromatic.h"
#include "../../include/my.h"

int do_we_div(char *fst_num, char *sec_num)
{
    if (my_strlen(fst_num) < my_strlen(sec_num))
        return (0);
    if (my_strlen(fst_num) > my_strlen(sec_num))
        return (2);
    for (int i = 0; fst_num[i]; i++) {
        if (fst_num[i] > sec_num[i])
            return (2);
        if (fst_num[i] < sec_num[i])
            return (0);
    }
    return (1);
}

char *div_calc(char *fst_abs, char *sec_abs)
{
    char *ans = "0";
    char *temp;
    int i = 0;

    for (; fst_abs[0] == '0'; ++fst_abs);
    if ((do_we_div(fst_abs, sec_abs) == 0))
        return ("0");
    for (int i = 0; i != -1; i++) {
        temp = infin_mult(sec_abs, ans);
        if (do_we_div(fst_abs, temp) == 1)
            return (ans);
        if (do_we_div(fst_abs, temp) == 2)
            ans = infin_add(ans, "1");
        if (do_we_div(fst_abs, temp) == 0)
            return (infin_sub(ans, "1"));
    }
    return (ans);
}

char *div_glob(char *fst_abs, char *sec_abs)
{
    int sec_length = my_strlen(sec_abs);
    int length_dif = my_strlen(fst_abs) - my_strlen(sec_abs);
    char *sent = malloc(sizeof(char) * sec_length + 4);
    char *ans = malloc(sizeof(char) * length_dif + 3);
    char *calc;
    int i = 0;
    int p = 0;

    for (i = 0; i != sec_length; i++)
        sent[i] = fst_abs[i];
    for (int j = 0; sec_abs[j]; j++) {
        if (sec_abs[j] > sent[j]) {
            sent[i++] = fst_abs[sec_length + p++];
            length_dif -= 1;
            break;
        }
        if (sent[j] > sec_abs[j])
            break;
    }
    sent[i] = '\0';
    for (i = 0; i != length_dif + 1; i++) {
        if (i == length_dif)
            p = 0;
        calc = div_calc(sent, sec_abs);
        ans[i] = calc[0];
        sent = my_strdup(rest(sent, sec_abs, ans[i]));
        sent[my_strlen(sent)] = fst_abs[sec_length + i + p];
    }
    return (ans);
}