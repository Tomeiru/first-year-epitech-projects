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

response_t *send_command(char *cmd, int response_type)
{
    int len = strlen(cmd);

    write(1, cmd, len);
    write(1, "\n", 1);
    return (get_response(response_type));
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
    switch(type) {
        case 2:
            response->data = read_data_2(args);
            break;
        case 3:
            response->data = read_data_3(args);
            break;
        case 4:
            response->data = read_data_4(args);
            break;
    }
    return (response);
}