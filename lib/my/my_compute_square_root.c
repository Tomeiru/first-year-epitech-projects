/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int res = 0;
    int n = 0;

    if (nb <= 0)
        return (0);
    if (nb > 2147483647 || nb < -2147483647)
        return (0);

    while (nb != n) {
        if (n * n > nb)
            return (0);
        if (n * n == nb)
            return (n);
        res = n * n;
        n++;
    }
}
