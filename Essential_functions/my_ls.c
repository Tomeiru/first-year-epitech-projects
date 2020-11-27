/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_ls
*/

#include "my_ls.h"

char *ls_flag_verif(char *str, char *flag)
{
    char *flaglist = "lRdrt";

    if (my_strlen(str) == 1)
        return (flag);
    for (int i = 1; str[i]; i++) {
        if (str[i] != 'l' && str[i] != 'R' && str[i] != 'd' && str[i] != 'r'
        && str[i] != 't') {
            my_printf("my_ls: invalid option -- '%c'\n", str[i]);
            exit(84);
        }
    }
    for (int i = 1; str[i]; i++)
        for (int j = 0; flaglist[j]; j++)
            str[i] == flaglist[j] ? flag[j] = '1' : 0;
    return (flag);
}

char *ls_flag(int ac, char **av)
{
    char *flag = malloc(sizeof(char) * 6);

    for (int i = 0; i < 5; i++)
        flag[i] = '0';
    flag[5] = '\0';
    for (int i = 0; i < ac; i++) {
        if (av[i][0] == '-')
            flag = ls_flag_verif(av[i], flag);
    }
    return (flag);
}

char **arg_to_path(int ac, char **av, int path_counter)
{
    char **path_array = malloc(sizeof(char *) * (path_counter + 1));
    int j = 0;

    for (int i = 0; i < ac; i++)
        if (av[i][0] != '-' || (av[i][0] == '-' && av[i][1] == '\0'))
            path_array[j++] = my_strdup(av[i]);
    path_array[j] = NULL;
}

int is_there_path(int ac, char **av)
{
    int counter = 0;

    for (int i = 1; i < ac; i++)
        if (av[i][0] != '-' || (av[i][0] == '-' && av[i][1] == '\0'))
            counter++;
    return (counter);
}

void ls_arguments(int ac, char **av)
{
    int path_counter = is_there_path(ac, av);
    char *ls_flags = ls_flag(ac, av);
    char **path_array;

    if (path_counter != 0) {
        path_array = arg_to_path(ac, av, path_counter);
    }
    else
        ls_sorter(ls_flags, ".");
}

int my_ls(int ac, char **av)
{
    if (ac == 1)
        no_arguments();
    else
        ls_arguments(ac, av);
    return (0);
}