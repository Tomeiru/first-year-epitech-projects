/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** movements
*/

#include <stdlib.h>
#include <string.h>
#include "comms.h"

void move_car(float speed)
{
    char cmd[20];

    if (speed >= 0) {
        strcpy(cmd, "CAR_FORWARD:");
        gcvt(speed, 5, cmd + 12);
    } else {
        dprintf("go back\n");
        strcpy(cmd, "CAR_BACKWARDS:");
        gcvt(speed, 5, cmd + 14);
    }
    response_destroy(send_command(cmd, 1));
}

void rotate_car(float rot)
{
    char cmd[16];

    strcpy(cmd, "WHEELS_DIR:");
    gcvt(rot, 5, cmd + 11);
    response_destroy(send_command(cmd, 1));
}