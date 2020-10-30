/*
** EPITECH PROJECT, 2020
** Bistromatic
** File description:
** calc
*/

#include "../../include/bistromatic.h"
#include "../../include/my.h"

char *mod_loop(char *fst_abs, char *sec_abs, char *sent, int more)
{
    int length_dif = my_strlen(fst_abs) - my_strlen(sec_abs);
    int p = 0;
    char *ans = malloc(sizeof(char) * length_dif + 3);
    char *modulo = malloc(sizeof(char) * my_strlen(sec_abs) + 4);

    if (more == 1) {
        length_dif -= 1;
        p = 1;
    }
    for (int i = 0; i != length_dif + 1; i++) {
        i == length_dif ? p = 0: 0;
        ans[i] = div_calc(sent, sec_abs)[0];
        sent = my_strdup(rest(sent, sec_abs, ans[i]));
        modulo = my_strdup(sent);
        sent[my_strlen(sent)] = fst_abs[my_strlen(sec_abs) + i + p];
    }
    for (; modulo[0] == '0' && my_strlen(modulo) != 1; ++modulo);
    return (modulo);
}

char *mod_glob(char *fst_abs, char *sec_abs)
{
    char *sent = malloc(sizeof(char) * my_strlen(sec_abs) + 4);
    char *modulo;
    int i = 0;
    int more = 0;

    for (i = 0; i != my_strlen(sec_abs); i++)
        sent[i] = fst_abs[i];
    for (int j = 0; sec_abs[j]; j++) {
        if (sec_abs[j] > sent[j]) {
            sent[i++] = fst_abs[my_strlen(sec_abs)];
            more = 1;
            break;
        }
        if (sent[j] > sec_abs[j])
            break;
    }
    sent[i] = '\0';
    modulo = mod_loop(fst_abs, sec_abs, sent, more);
    return (modulo);
}