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

void set_timestamp_from_str(timestamp_t *timestamp, char *str);

#endif /* !NEED4STEK_H_ */
