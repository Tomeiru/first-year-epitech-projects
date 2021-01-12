/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** main
*/

int main(int ac, char **av)
{
    if (error(ac, av) == 84)
        return (84);
    if (ac == 1) {
        write(1, "\n", 1);
        return (0);
    }
    else
        return (countwords(av[1]));
}
