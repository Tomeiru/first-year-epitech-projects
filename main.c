/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

int main(int argc, char **argv)
{
    if (argc == 2) {
        my_put_nbr(mix(argv[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}