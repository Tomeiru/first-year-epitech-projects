/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** check_syntax_comment
*/

#include "asm.h"

static int check_label_before_name(char **file_array, int label_presence)
{
    if (get_info_label(file_array[label_presence]) == 1)
        return (-2);
    return (0);
}

static int check_syntax_arg(char *line_comment)
{
    char **args = get_args_arr(line_comment, 0);
    int length = 0;
    int i = 0;

    if (args[0] == NULL || args[1] != NULL || args[0][0] != '"')
        return (-3);
    args[0]++;
    for ( ; args[0][i] != '"' && args [0][i] != '\0'; i++) {
        length++;
        if (length > 2048)
            return (-4);
        if (args[0][i] != 9 && args[0][i] < 32)
            return (-3);
    }if (args[0][i] == '\0')
        return (-3);
    return (check_after_quotes(line_comment));
}

int check_syntax_comment(char **file_array, int comment_presence)
{
    int return_value = 0;

    if (comment_presence < 0)
        return (comment_presence);
    if (check_label_before_name(file_array, comment_presence) == -2)
        return (-2);
    return_value = check_syntax_arg(file_array[comment_presence]);
    if (return_value < 0)
        return (return_value);
    return (0);
}