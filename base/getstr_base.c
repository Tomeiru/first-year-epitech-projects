/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-mathieu.brujan
** File description:
** getstr_base
*/

int my_getstr_base(char *nbr, char *base, int len, char *res)
{
    int len_base = my_strlen(base);
    int i;
    int n;

    if (nbr[0] == '-')
        my_putchar('-');
    for (i = 0; base[i] != nbr[0]; i++);
    n = i;
    res = infinadd(res, infinadd(my_nbrtostr(n), infinpower(len_base, len)));
    if (len > 0) {
        len--;
        nbr++;
        res = my_getnbr_base(nbr, base, len, res);
    }
    return (res);
}