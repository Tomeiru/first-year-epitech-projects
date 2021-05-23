/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_syntax_name
*/

#include "asm.h"

static int check_label_before_name(char **file_array, int name_presence)
{
    int idx = 0;

    for (int i = 0; i <= name_presence; i++) {
        for ( ; file_array[i][idx] == ' ' || file_array[i][idx] == 9; idx++);
        if (file_array[i][idx] == '#') {
            return (0);
        }if (get_info_label(file_array[i]) == 1)
            return (-2);
    }
    return (0);
}

static int check_syntax_arg(char *line_name)
{
    char **args = get_args_arr(line_name, 0);
    int length = 0;
    int i = 0;

    if (args[0] == NULL || args[1] != NULL || args[0][0] != '"')
        return (-3);
    args[0]++;
    for ( ; args[0][i] != '"' && args [0][i] != '\0'; i++) {
        length++;
        if (length > 128)
            return (-4);
        if (args[0][i] != 9 && args[0][i] < 32)
            return (-3);
    }if (args[0][i] == '\0')
        return (-3);
    return (check_after_quotes(line_name));
}

int check_syntax_name(char **file_array, int name_presence)
{
    int return_value = 0;

    if (name_presence < 0)
        return (name_presence);
    if (check_label_before_name(file_array, name_presence) == -2)
        return (-2);
    return_value = check_syntax_arg(file_array[name_presence]);
    if (return_value < 0)
        return (return_value);
    return (0);
}