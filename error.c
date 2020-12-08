/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-mathieu.brujan
** File description:
** error
*/

static int allowed_char(char c, int error)
{
    if (c > '9' || c < '0')
        return (84);
    return (error);
}

int error(int ac, char **av)
{
    int error = 0;
    int j = 0;

    if (ac < 2)
        return (84);
    for (int i = 1; av[i]; i++) {
        if (av[i][0] == '-')
            j = 1;
        else
            j = 0;
        for ( ; av[i][j]; j++)
            error = allowed_char(av[i][j], error);
    }
    return (error);
}