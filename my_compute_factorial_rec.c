/*
** EPITECH PROJECT, 2020
** my_compute_factorial_res
** File description:
** my_compute_factorial_res
*/

int my_compute_factorial_rec(int nb)
{
    int res = 0;

    if (nb >= 13)
        return (0);
    if (nb < 0)
        return (0);
    if (nb == 0)
        return (1);
    if (nb == 1)
        return (1);
    res = nb * my_compute_factorial_rec(nb - 1);
    return (res);
}
