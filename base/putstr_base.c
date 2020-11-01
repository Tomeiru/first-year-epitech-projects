/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-mathieu.brujan
** File description:
** putstr_base
*/

#include "../include/bistromatic.h"
#include "../include/my.h"

char *infinpower(char *nbr, int power)
{
    char *result = "1";

    for (int i = 1; i <= power; i++) {
        result = infin_mult(result, nbr);
    }
    return (result);
}

char *nbrtostr(int nbr)
{
    char *str = malloc(10);
    int i = 0;
    if (nbr == 0)
        return("0");
    for (; nbr > 0; i++)
    {
        str[i] = nbr % 10 + 48;
        nbr = nbr / 10;
    }
    str[i] = '\0';
    str = my_revstr(str);
    return(str);
}

int print_str_base(char *nbr)
{
    int i;

    for (i = 1; nbr[i] == '0'; i++);
    if (my_strlen(nbr) != i)
        for (;nbr[0] == '0'; nbr++);
    my_putstr(nbr);
    my_putchar('\n');
    return (0);
}

int calc_lenght(char *str, char *base)
{
    int len = 0;
    char *len_base = nbrtostr(my_strlen(base));
    char *result = infin_sub(infinpower(len_base, len), str);

    for (; result[0] == '-'; len ++){
        result = infin_sub(infinpower(len_base, len), str);
    }
    return(len);
}


int *str_base(char *nbr , char *base, char *op)
{
    char *len_base = nbrtostr(my_strlen(base));
    int len = 100;
    char *temp = malloc(10000);
    char *result = malloc(10000);

    if (nbr[0] == '-') {
        my_putchar(op[3]);
        nbr++;
    }
    if (nbr[0] == '0')
       result[0] = base[0];
    len = calc_lenght(nbr, base);
    for (int i = 0; len >= 0; len--) {
        temp = infin_div(nbr, infinpower(len_base, len));
        nbr = infin_mod(nbr, infinpower(len_base, len));
        result[i++] = base[my_getnbr(temp)];
        result[i] = '\0';
    }
    print_str_base(result);
    return (0);
}