/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_label_char
*/

#include "asm.h"

int check_label_arg(char *arg)
{
    char label_char[37] = "abcdefghijklmnopqrstuvwxyz_0123456789";

    if (arg[0] != ':')
        return (-2);
    if (arg[1] == '\0')
        return (-3);
    arg++;
    for (int i = 0; arg[i]; i++) {
        for (int j = 0; label_char[j]; j++) {
            if (label_char[j] == arg[i])
                break;
            if (j == 36)
                return (-3);
        }
    }
    return (0);
}