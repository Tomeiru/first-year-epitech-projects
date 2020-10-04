/*
** EPITECH PROJECT, 2020
** my_compute_power
** File description:
** my_compute_power
*/

int my_compute_power_rec(long nb, long p)
{
    int res = 0;

    if (p > 2147483647 || nb > 2147483647)
        return (0);
    if (p < -2147483647 || nb < -2147483647)
        return (0);
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);

    res = nb * my_compute_power_rec(nb, p - 1);
}
