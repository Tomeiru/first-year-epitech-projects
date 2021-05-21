/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** d
*/

#include "asm.h"

int check_after_quotes(char *line_name)
{
    int quotes = 0;

    for (int i = 0; line_name[i]; i++) {
        if (quotes == 2 && line_name[i] != ' ' && line_name[i] != 9)
            return (-3);
        if (line_name[i] == '"')
            quotes++;
    }
    return (0);
}