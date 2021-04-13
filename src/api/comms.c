/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** comms
*/

#include <stdlib.h>
#include <unistd.h>

void send_command(char *cmd, int len)
{
    write(1, cmd, len);
}

response_t get_reponse(char type)
{

}