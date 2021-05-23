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
    int *counter = malloc(sizeof(int) * 2);

    counter[0] = 0;
    counter[1] = 0;
    for (int i = 1; i != ac; i++)
        if (my_strcmp("-dump", av[i]) == 0)
            counter[0]++;
        else if (check_cor(".cor", av[i]) == 1)
            counter[1]++;
    return (counter);
}

int check_args(int ac, char **av)
{
    int *nbr = args_counter(ac, av);
    int nbr_champ = nbr[1];

    if (nbr[0] > 1) {
        write(2, "Multiple definition of dump\n", 28);
        return (-1);
    }if (nbr[1] < 2) {
        write(2, "You need at least two .cor file loaded for ", 43);
        write(2, "the program to execute\n", 23);
        return (-1);
    }if (flag_errors(ac, av) == 84) {
        write(2, "Your flags are incorrect\n", 25);
        return (-1);
    }free(nbr);
    return (nbr_champ);
}

int error_manager(int ac, char **av)
{
    int nbr_champ = check_args(ac, av);

    if (ac < 3) {
        write(2, "Usage: ./corewar [-dump cycle_nb]", 33);
        write(2, "[[-a load_addr] [-n prog_nb] prog.cor] ...\n", 43);
        exit(84);
    }if (nbr_champ == -1)
        exit(84);
    return (nbr_champ);
}