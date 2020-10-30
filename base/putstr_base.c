/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-mathieu.brujan
** File description:
** putstr_base
*/

char *infinpower(char *nbr, int power)
{
    char *result = malloc(100);

    for (int i = 0; i < power; i++)
        result = infinmul(result, nbr);
    printf("%s\n", result);
    return (result);
}

char *my_nbrtostr(int nbr)
{
    char *str = malloc(10);
    int i = 0;
    for (; nbr > 0; i++)
    {
        str[i] = nbr % 10 + 48;
        nbr = nbr / 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return(str);
}

int  putstr_base(char *nbr , char *base, int m)
{
    int n = my_strlen(nbr) - 1;
    int cpt;
    char *former_result;
    char *result;
    char *lenght_base = my_nbrtostr(my_strlen(base));

    for (cpt = 0; nbr[n] != base[cpt]; cpt++);
    if (nbr[n] == '-') {
        my_putchar('-');
        nbr[n] = '\0';
    }
    if (n > 0) {
        nbr[n] = '\0';
        m++;
        former_result = putstr_base(nbr, base, m);
    }
    result = infinadd(my_nbrtostr(cpt), infinpower(lenght_base, m));
    return (result);
}

int main (int ac, char **av)
{
    putstr_base(av[1], av[2], 0);
    my_putchar('\n');
    return (0);
}