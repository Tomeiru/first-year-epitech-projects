/*
** EPITECH PROJECT, 2021
** B-MAT-200-STG-2-1-107transfer-alessandro.tosi
** File description:
** main
*/

#include "transfer.h"

char *my_revstr(char *str)
{
    char temp;
    int j = strlen (str) - 1;
    int i = 0;

    for ( ; i <= j; i ++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
    return (str);
}

void check_arg(char *str)
{
    if (str[0] == '*')
        exit(84);
    str = my_revstr(str);
    if (str[0] == '*')
        exit(84);
    str = my_revstr(str);
    for (int i = 0; str[i]; i++) {
        if (!(str[i] == '*' || str[i] == '-'|| (str[i] >= '0' && str[i] <= '9')))
            exit(84);
        if (str[i] == '*' && str[i + 1] == '*')
            exit(84);
    }
}

void error(int ac, char **av)
{
    if (ac % 2 != 1 || ac == 1)
        exit (84);
    for (int i = 1; av[i]; i++)
        check_arg(av[i]);
}

int main(int ac, char **av)
{
    error(ac, av);
    return (transfer(ac, av));
}