/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** titration
*/

#ifndef TITRATION_H_
#define TITRATION_H_

#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct info_s {
    double *ph;
    double *volume;
    double *first;
    double *second;
    double *estimation;
    int equivalence_pos;
    int nb_line;
} info_t;

char *file_reader(char *filepath, int *len);

#endif /* !TITRATION_H_ */
