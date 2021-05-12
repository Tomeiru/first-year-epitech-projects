/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** main file
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "comms.h"

void run(void);
void move(float data[32]);
void turn(float left, float right);

int main(void)
{
    response_destroy(send_command("START_SIMULATION", 1));
    response_destroy(send_command("CAR_FORWARD:0.1f", 1));
    response_destroy(send_command("CYCLE_WAIT:5", 3));
    run();
    response_destroy(send_command("STOP_SIMULATION", 1));
    return (0);
}

void run(void)
{
    response_t *response;
    char run = 1;

    while (run) {
        response = send_command("GET_INFO_LIDAR", 2);
        if (response->course.type == TRACK)
            run = 0;
        move((float*) response->data);
        response_destroy(response);
    }
    response_destroy(send_command("CAR_FORWARD:0f", 1));
}

void move(float *data)
{
    float speed[] = {-0.1, -0.01, 0.001, 0.1, 0.15, 0.2, 0.3, 0.4, 0.7, 0.9};
    float dist[] = {10, 30, 100, 200, 300, 500, 600, 900, 1200, 3010};
    float left = get_average(data, 16);
    float right = get_average(data + 16, 16);

    dprintf(2, "\n--- %f / %f ---\n", left, right);
    for (int i = 0; i < 10; i++) {
        if (left <= dist[i] || right <= dist[i]) {
            dprintf(2, "speed: %f\n", speed[i]);
            move_car(speed[i]);
            break;
        }
    }
    turn(left, right);
}

void turn(float left, float right)
{
    float rot[] = {0.7, 0.5, 0.4, 0.3, 0.2, 0.1, 0};
    float dist[] = {110, 150, 200, 250, 350, 1000, 3010};

    for (int i = 0; i < 8; i++) {
        if (left <= dist[i] || right <= dist[i]) {
            dprintf(2, "rot: %f\n", rot[i]);
            rotate_car(rot[i] * (left > right ? 1 : -1));
            break;
        }
    }
}