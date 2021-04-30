/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** comms header
*/

#ifndef COMMS_H_
#define COMMS_H_

#include "need4stek.h"

#define SIM_NOT_LAUNCH 0
#define NOTINHG_TO_REPORT 1
#define SIM_RUNNING 1
#define ERROR 2
#define CHECKPOINT_ERROR 5
#define NETWORK_FAILURE 6
#define SERVER_ERROR 7
#define CLIENT_ERROR 8
#define EOF_REACHED 9
#define SIM_ENDED 10
#define EMPTY_CMD 11
#define UNKNOWN_CMD 12
#define WRONG_ARGS 13
#define TOO_MANY_ARGS 14
#define PIPE_FAILURE 15
#define WRONG_ARG_VALUE 16
#define CAM_INFO_FAILURE 17
#define CMD_NOT_FOUND 18
#define SIM_ALREADY_RUNNING 19
#define CYCLE_DONE 20
#define SENSOR_FAILURE 21
#define SCENE_NOT_CONTAINING_3_CPS 22
#define TIMER_INIT_FAILURE 23
#define TIMER_GET_FAILURE 24
#define MAP_LOAD_FAILURE 25

typedef enum status_e {
    OK,
    KO
} status_t;

typedef enum course_info_type_e {
    NOTHING,
    FIRST_CP,
    CP,
    LAP,
    TRACK
} course_info_type_t;

typedef struct course_info_s {
    course_info_type_t type;
    int id;
    timestamp_t timestamp;
} course_info_t;

typedef struct response_s {
    int value_id;
    status_t status;
    void *data;
    course_info_t course;
} response_t;

response_t *send_command(char *cmd, int response_type);
response_t *get_response(int type);

response_t *create_basic_response(char **array, int size);
char *get_response_str(void);
char **split_response(char *response, int *array_size);
void set_course_status(response_t *response, char **array, int size);
void response_destroy(response_t *response);

float *read_data_2(char **args);
float *read_data_3(char **args);
long *read_data_4(char **args);

#endif /* !COMMS_H_ */
