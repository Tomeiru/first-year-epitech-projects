/*
** EPITECH PROJECT, 2020
** my_compute_factorial_it
** File description:
** my_compute_factorial_it
*/

int my_compute_factorial_it(int nb)
{
    int res = 0;
    if (nb < 0)
        return (0);
    if (nb == 0)
        return (1);
    if (nb == 1)
        return (1);

    res = nb * my_compute_factorial_it(nb - 1);
    
    return (res);
}