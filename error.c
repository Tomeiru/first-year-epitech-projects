/*
** EPITECH PROJECT, 2020
** error
** File description:
** error
*/

int error (int ac, char **av)
{
    for (int i = 0; av[i][0]; i++) {
        if (my_ltr_isalpha(av[i][0]) == 0)
            return(1);
        if (av[i][1] != '\0')
            return (1);
    }
    for (int j = 0; av[1][j]; j++)
        if (my_str_isnotalpha(av[1]) == 1)
            return (1);
    return (0);
}