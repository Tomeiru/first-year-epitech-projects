/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** titration
*/

#include "titration.h"

int get_nb_line(char *file)
{
    int count = 0;

    for (int i = 0; file[i]; i++)
        if (file[i] == '\n')
            count++;
    return (count);
}

void get_ph_volume(info_t *info_struct, char *file)
{
    char *endptr;
    int i = 0;

    info_struct->ph = malloc(sizeof(double) * (info_struct->nb_line + 1));
    info_struct->volume = malloc(sizeof(double) * (info_struct->nb_line + 1));
    info_struct->volume[0] = strtod(file, &endptr);
    endptr++;
    info_struct->ph[0] = strtod(endptr, &endptr);
    endptr++;
    for (i = 1; i < info_struct->nb_line; i++) {
        info_struct->volume[i] = strtod(endptr, &endptr);
        endptr++;
        info_struct->ph[i] = strtod(endptr, &endptr);
        endptr++;
    }info_struct->volume[i] = -1;
    info_struct->ph[i] = -1;
}

info_t *fill_struct(char *file)
{
    info_t *info_struct = malloc(sizeof(info_t));

    info_struct->nb_line = get_nb_line(file);
    get_ph_volume(info_struct, file);
    info_struct->first = malloc(sizeof(double) * (info_struct->nb_line - 1));
    info_struct->second = malloc(sizeof(double) * (info_struct->nb_line - 3));
    return (info_struct);
}

void equivalence_point(info_t *info_struct)
{
    int highest = 0;

    for (int i = 0; info_struct->first[i] != -1; i++)
        if (info_struct->first[i] > info_struct->first[highest])
            highest = i;
    printf("\nEquivalence point at %.1f ml\n", info_struct->volume[highest + 1]);
    info_struct->equivalence_pos = highest + 1;
}

void first_derivation(info_t *info_struct)
{
    double next = 0;
    double before = 0;
    double coeffnext = 0;
    double coeffbef = 0;

    for (int i = 0; i < info_struct->nb_line - 2; i++) {
        coeffnext = (info_struct->volume[i + 2] - info_struct->volume[i + 1]);
        coeffbef = (info_struct->volume[i + 1] - info_struct->volume[i]);
        next = (info_struct->ph[i + 2] - info_struct->ph[i + 1]) / coeffnext;
        before = (info_struct->ph[i + 1] - info_struct->ph[i]) / coeffbef;
        info_struct->first[i] = ((next * coeffbef) + (before * coeffnext)) / (coeffbef + coeffnext);
    }info_struct->first[info_struct->nb_line - 2] = -1;
    printf("Derivative:\n");
    for (int i = 0; info_struct->first[i] != -1; i++)
        printf("%.1f ml -> %.2f\n", info_struct->volume[i + 1], info_struct->first[i]);
    equivalence_point(info_struct);
}

void second_derivation(info_t *info_struct)
{
    double next = 0;
    double before = 0;
    double coeffnext = 0;
    double coeffbef = 0;

    for (int i = 0; i < info_struct->nb_line - 4; i++) {
        coeffnext = (info_struct->volume[i + 3] - info_struct->volume[i + 2]);
        coeffbef = (info_struct->volume[i + 2] - info_struct->volume[i + 1]);
        next = (info_struct->first[i + 2] - info_struct->first[i + 1]) / coeffnext;
        before = (info_struct->first[i + 1] - info_struct->first[i]) / coeffbef;
        info_struct->second[i] = ((next * coeffbef) + (before * coeffnext)) / (coeffbef + coeffnext);
    }info_struct->second[info_struct->nb_line - 4] = -1;
    printf("\nSecond derivative:\n");
    for (int i = 0; info_struct->second[i] != -1; i++)
        printf("%.1f ml -> %.2f\n", info_struct->volume[i + 2], info_struct->second[i]);
}

int titration(char *file)
{
    info_t *info_struct = fill_struct(file);

    first_derivation(info_struct);
    second_derivation(info_struct);
    printf("\n");
    return (0);
}