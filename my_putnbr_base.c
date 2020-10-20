/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday06-lilou.stoll-metz
** File description:
** my_putnbr_base
*/

int  my_putnbr_base(int nbr , char  const *base)
{
    int n = my_strlen(base);

    if (nbr < 0) {
        nbr = nbr * -1;
        my_putchar('-');
    }
    if (nbr > n) {
        my_putnbr_base(nbr/n, base);
    }
    my_putchar(base[nbr % n]);
}