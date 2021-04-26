/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** comms
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "comms.h"

void send_command(char *cmd)
{
    int len = strlen(cmd);

    write(1, cmd, len);
    write(1, "\n", 1);
}

response_t *get_response(int type)
{
    char *str = get_response_str();
    char **args = NULL;
    int args_nb = 0;
    response_t *response = NULL;

    if (!str || !(args = split_response(str, &args_nb)) ||
    !(response = create_basic_response(args, args_nb)))
        return (NULL);
    if (type == 2)
        response->data = read_data_2(args);
    else if (type == 3)
        response->data = read_data_3(args);
    else
        response->data = read_data_4(args);
    return (response);
}