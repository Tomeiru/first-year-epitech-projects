/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** response
*/

#include <stdlib.h>

response_t *create_basic_response(char **array, int size)
{
    response_t *response;

    if (size < 3 || !(response = malloc(sizeof(response_t))))
        return (NULL);
    response->value_id = atoi(array[0]);
    response->status = !strcmp(array[1], "OK") ? 0 : 1;
    set_course_status(response, array[size - 1]);
    return (response);
}

char *get_response_str(void)
{
    char *response = NULL;
    size_t n = 0:
    ssize_t len = getline(&response, &n, stdin);

    if (len == -1) {
        wrtie("Cannot read response. Exit.\n", 28);
        exit(84);
    }
    response[len - 1] = 0;
    return (response);
}

char **split_response(char *response, int *array_size)
{
    char **array = NULL;
    char *part = strtok(response, ";");
    int size = 0;

    while (part) {
        array = realloc(array, sizeof(char*) * (size++));
        if (!array)
            return (NULL);
        array[size - 1] = part;
        part = strtok(response, ";");
    }
    *array_size = size;
    return (array);
}

void set_course_status(response_t *response, char **array, int size)
{
    response->course = (course_info_t) {0, 0, (timestamp_t) {0, 0}};
    if (!strcmp(array[size - 1], "No further info"))
        return;
}