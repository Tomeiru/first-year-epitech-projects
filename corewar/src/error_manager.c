/*
** EPITECH PROJECT, 2021
** Corewar
** File description:
** error
*/

#include "corewar.h"

int check_cor(char *cor, char *str)
{
    int len = my_strlen(str);
    int k = 0;
    int counter = 0;

    for (int i = len - 4; str[i] != '\0'; i++) {
        if (str[i] == cor[k])
            counter++;
        k++;
    }
    if (counter == 4)
        return (1);
    return (0);
}

int *args_counter(int ac, char **av)
{
    int counter[2] = {0, 0};

    for (int i = 1; i != ac; i++)
        if (my_strcmp("-dump", av[i]) == 1)
            counter[0]++;
        else if (check_cor(".cor", av[i]) == 1)
            counter[1]++;
    return (counter);
}

int check_args(int ac, char **av)
{
    int nbr[2] = args_counter(ac, av);

    if (nbr[0] != 1 || nbr[1] < 2 || file_errors(ac, av, nbr[1]) == 84)
        return (84);
}

void error_manager(int ac, char **av)
{
    if (ac < 5 || check_args(ac, av) == 84)
        exit(84);
}