/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** main header
*/

#ifndef NEED4STEK_H_
#define NEED4STEK_H_

typedef struct timestamp_s {
    long seconds;
    long nanoseconds;
} timestamp_t;

void move(float *data);
void turn(float left, float right);

void move_car(float speed);
void rotate_car(float rot);

void set_timestamp_from_str(timestamp_t *timestamp, char *str);

float get_average(float *data, int size);

#endif /* !NEED4STEK_H_ */
