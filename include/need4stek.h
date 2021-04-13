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
} timestamp_s;

/* API */
void send_command(char *cmd, int len);
unsigned int get_response_int(void);
float get_response_float(void);

#endif /* !NEED4STEK_H_ */
