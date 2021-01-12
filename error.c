/*
** EPITECH PROJECT, 2020
** 101pong
** File description:
** main
*/

int error(int ac, char **av)
{
    if (ac == 1 || ac == 2)
        return (0);
    else {
        write(2, "Error: bad number of argument\n", 30);
        return (84);
    }
}
