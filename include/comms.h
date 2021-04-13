/*
** EPITECH PROJECT, 2021
** need4stek
** File description:
** comms header
*/

#ifndef COMMS_H_
#define COMMS_H_

#include "need4stek.h"

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
    int status;
    void *response;
    course_info_t course;
} response_t;

#endif /* !COMMS_H_ */
