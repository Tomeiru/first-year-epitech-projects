/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(mix(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}