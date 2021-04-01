/*
** EPITECH PROJECT, 2021
** B-CPE-210-STG-2-1-stumper3-lilou.stoll-metz
** File description:
** main
*/

#include "stumper.h"

static void is_num_for_str(char *str, info_t *info_struct)
{
    for (int i = 0; str[i]; i++)
        if (!(str[i] >= '0' && str[i] <= '9'))
            exit_and_free(84, info_struct);
}

static int check_params(char **av, info_t *info_struct)
{
    int error = 0;

    if (strcmp("-n", av[1]) == 0 && strcmp("-s", av[3]) == 0)
        error = 2;
    if (strcmp("-s", av[1]) == 0 && strcmp("-n", av[3]) == 0)
        error = 4;
    if (error == 0)
        exit_and_free(84, info_struct);
    return (error);
}

static void check_str(char *str, info_t *info_struct)
{
    if (strlen(str) > 9) {
        free(info_struct->numbers);
        exit_and_free(84, info_struct);
    }
    for (int i = 0; str[i]; i++)
        if (str[i] <= 31) {
            free(info_struct->numbers);
            exit_and_free(84, info_struct);
        }
}

void error_three_arg(char **av, info_t *info_struct)
{
    if (strcmp("-n", av[1]) != 0)
        exit_and_free(84, info_struct);
    is_num_for_str(av[2], info_struct);
    info_struct->numbers = strdup(av[2]);
    info_struct->chars = strdup("000000000");
    info_struct->lenght_chars = 9;
    if (info_struct->numbers == NULL ||
        info_struct->chars == NULL)
        exit_and_free(84, info_struct);
}

void error_five_arg(char **av, info_t *info_struct)
{
    int value = 0;

    value = check_params(av, info_struct);
    is_num_for_str(av[value], info_struct);
    info_struct->numbers = strdup(av[value]);
    if (info_struct->numbers == NULL)
         exit_and_free(84, info_struct);
    if (value == 2) {
        check_str(av[4], info_struct);
        info_struct->chars = strdup(av[4]);
        info_struct->lenght_chars = strlen(av[4]);
    }else {
        check_str(av[2], info_struct);
        info_struct->chars = strdup(av[2]);
        info_struct->lenght_chars = strlen(av[2]);
    }if (info_struct->chars == NULL)
         exit_and_free(84, info_struct);
}
