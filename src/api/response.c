/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** response
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "comms.h"
#include "additionnal.h"

response_t *create_basic_response(char **array, int size)
{
    response_t *response;

    if (size < 3 || !(response = malloc(sizeof(response_t))))
        return (NULL);
    response->value_id = atoi(array[0]);
    response->status = !strcmp(array[1], "OK") ? OK : KO;
    set_course_status(response, array, size);
    return (response);
}

char *get_response_str(void)
{
    char *response = NULL;
    size_t n = 0;
    ssize_t len = getline(&response, &n, stdin);

    if (len == -1) {
        write(2, "Cannot read response. Exit.\n", 28);
        exit(84);
    }
    response[len - 1] = 0;
    return (response);
}

char **split_response(char *response, int *array_size)
{
    char **array = NULL;
    char *part = strtok(response, ":");
    int size = 0;

    while (part) {
        array = realloc(array, sizeof(char*) * (size++));
        if (!array)
            return (NULL);
        array[size - 1] = part;
        part = strtok(response, ":");
    }
    *array_size = size;
    return (array);
}

void set_course_status(response_t *response, char **array, int size)
{
    char *infos = NULL;

    response->course = (course_info_t) {0, 0, (timestamp_t) {0, 0}};
    if (!strcmp(array[size - 1], "No further info"))
        return;
    for (int i = 0; i < ADDITIONNAL_INFOS_NB; i++) {
        if (!strcmp(array[size - 2], ADDITIONNAL_INFOS_STR[i])) {
            response->course.type = ADDITIONNAL_INFOS_TYPE[i];
            break;
        }
    }
    infos = array[size - 1] + 1;
    response->course.id = atoi(infos);
    for (; *infos && *infos != '['; infos++);
    set_timestamp_from_str(&(response->course.timestamp), infos);
}