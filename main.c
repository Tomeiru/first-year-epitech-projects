/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

int main(int ac, char **av)
{
    if (ac == 2) {
        printf("%d\n", mix(av[1]));
        return (0);
    }
    return (84);
}