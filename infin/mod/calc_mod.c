/*
** EPITECH PROJECT, 2020
** Bistromatic
** File description:
** calc
*/

#include "../../include/bistromatic.h"
#include "../../include/my.h"

char *mod_glob(char *fst_abs, char *sec_abs)
{
    int sec_length = my_strlen(sec_abs);
    int length_dif = my_strlen(fst_abs) - my_strlen(sec_abs);
    char *sent = malloc(sizeof(char) * sec_length + 4);
    char *modulo = malloc(sizeof(char) * sec_length + 4);
    char *ans = malloc(sizeof(char) * length_dif + 3);
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
        ans[i] = div_calc(sent, sec_abs)[0];
        sent = my_strdup(rest(sent, sec_abs, ans[i]));
        modulo = my_strdup(sent);
        sent[my_strlen(sent)] = fst_abs[sec_length + i + p];
    }
    if (modulo[0] == '\0')
        return("0");
    return (modulo);
}