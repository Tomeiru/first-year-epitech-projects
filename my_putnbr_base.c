/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday06-lilou.stoll-metz
** File description:
** my_putnbr_base
*/

#include <stdio.h>
#include <stdlib.h>

int  my_putnbr_base(int nbr , char  const *base)
{
    int n = strlen(base);

    if (nbr > 0) {
        my_putchar('-');
        nbr *= -1;
    }
    if (nbr > n) {
        my_putnbr_base(nbr/n, base);
    }
    my_putchar(base[nbr % n]);
    return (0);
}

int power_it (int len_base, int n)
{
    int res = 1;
    for(int i = 1; i <= n; i ++) {
        res = res * len_base;
    }
    return (res);
}

int my_getnbr_base(char *nbr, char *base, int len, int res)
{
    int len_base = my_strlen(base);
    int i;
    int n;

    if (nbr[0] == '-')
        my_putchar('-');
    for (i = 0; base[i] != nbr[0]; i++);
    n = i;
    res += n * power_it(len_base, len);
    if (len > 0) {
        len--;
        nbr++;
        res = my_getnbr_base(nbr, base, len, res);
    }
    return (res);
}

int main (int ac, char**av)
{
    int res = my_getnbr_base(av[1], av[2], my_strlen(av[1]) - 1, res);
    printf("%i\n", res);
    return (0);
}