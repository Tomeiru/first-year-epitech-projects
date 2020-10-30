/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-mathieu.brujan
** File description:
** putstr_base
*/

char *infinpower(char *nbr, int power)
{
    char *result = "1";

    for (int i = 1; i <= power; i++)
        result = infin_mult(result, nbr);
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
    char *former_result = malloc(10000);
    char *result;
    char *lenght_base = my_nbrtostr(my_strlen(base));

    former_result = "0";
    for (cpt = 0; nbr[n] != base[cpt]; cpt++);
    result = infin_mult(my_nbrtostr(cpt), infinpower(lenght_base, m));
    m++;
    if (nbr[n] == '-') {
        my_putchar('-');
        nbr[n] = '\0';
    }
    if (n > 0) {
        nbr[n] = '\0';
        former_result = putstr_base(nbr, base, m);
    }
    result = infin_add(result, former_result);
    printf("%s\n", result);
    return (result);
}