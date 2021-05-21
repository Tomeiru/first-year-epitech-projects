/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_arg_str
*/

#include "asm.h"

static int get_arg_size_first(char *line, int label)
{
    int idx = 0;
    int ret = 0;

    for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
    for ( ; line[idx] != ' ' && line[idx] != 9 && line[idx] != '\0'; idx++);
    if (label == 1) {
        for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
        for ( ; line[idx] != ' ' && line[idx] != 9 && line[idx] != '\0'; idx++);
    }
    for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
    for ( ; line[idx] != ' ' && line[idx] != 9 &&
    line[idx] != ',' && line[idx] != '\0'; idx++)
        ret++;
    return (ret);
}

static int get_arg_size(char *line, int label, int idx)
{
    int comma = 0;
    int i = 0;
    int ret = 0;

    if (idx == 0)
        return (get_arg_size_first(line, label));
    for ( ; line[i]; i++) {
        if (line[i] == ',')
            comma++;
        if (comma == idx) {
            i++;
            break;
        }
    }for ( ; line[i] == ' ' || line[i] == 9; i++);
    for ( ; line[i] != ' ' && line[i] != 9 &&
    line[i] != ',' && line[i] != '\0'; i++)
        ret++;
    return (ret);
}

static char *get_arg_str_first(char *line, int label, char *arg)
{
    int idx = 0;
    int i = 0;

    for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
    for ( ; line[idx] != ' ' && line[idx] != 9 && line[idx] != '\0'; idx++);
    if (label == 1) {
        for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
        for ( ; line[idx] != ' ' && line[idx] != 9 && line[idx] != '\0'; idx++);
    }
    for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
    for ( ; line[idx] != ' ' && line[idx] != 9 &&
    line[idx] != ',' && line[idx] != '\0'; idx++)
        arg[i++] = line[idx];
    arg[i] = '\0';
    return (arg);
}

char *get_arg_str(char *line, int label, int idx)
{
    int size = get_arg_size(line, label, idx);
    char *arg = malloc(sizeof(char) * (size + 1));
    int comma = 0;
    int i = 0;
    int j = 0;

    if (idx == 0)
        return (get_arg_str_first(line, label, arg));
    for ( ; line[i]; i++) {
        if (line[i] == ',')
            comma++;
        if (comma == idx) {
            i++;
            break;
        }
    }for ( ; line[i] == ' ' || line[i] == 9; i++);
    for ( ; line[i] != ' ' && line[i] != 9 &&
    line[i] != ',' && line[i] != '\0'; i++)
        arg[j++] = line[i];
    arg[j] = '\0';
    return (arg);
}