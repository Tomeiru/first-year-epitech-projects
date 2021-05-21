/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** get_command_str
*/

#include "asm.h"

static int get_command_size(char *line, int label)
{
    int idx = 0;
    int ret = 0;

    if (label == 1) {
        for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
        for ( ; line[idx] != ' ' && line[idx] != 9 && line[idx] != '\0'; idx++);
    }for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
    for ( ; line[idx] != ' ' && line[idx] != 9 && line[idx] != '\0'; idx++)
        ret++;
    return (ret);
}

char *get_command_str(char *line, int label)
{
    int size = get_command_size(line, label);
    char *command = malloc(sizeof(char) * (size + 1));
    int idx = 0;
    int i = 0;

    if (label == 1) {
        for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
        for ( ; line[idx] != ' ' && line[idx] != 9 && line[idx] != '\0'; idx++);
    }for ( ; line[idx] == ' ' || line[idx] == 9; idx++);
    for ( ; line[idx] != ' ' && line[idx] != 9 && line[idx] != '\0'; idx++)
        command[i++] = line[idx];
    command[i] = '\0';
    return (command);
}