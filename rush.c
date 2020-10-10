/*
** EPITECH PROJECT, 2020
** Rush
** File description:
** Rush
*/

int rush(int ac, char **av)
{
    int res = 0;

    for (int i = 2; i < ac; ++i) {
        res = 0;
        my_putchar(av[i][0]);
        for (int j = 0; av[1][j]; ++j) {
            if (av[i][0] >= 'A' && av[i][0] <= 'Z')
                av[i][0] += 32;
            if (av[1][j] == av[i][0] || av[1][j] == av[i][0] - 32)
                ++res;
        }
        my_putchar(':');
        my_put_nbr(res);
        my_putfloat(res, ltr_max (av));
        my_putchar('\n');
    }
    return (0);
}