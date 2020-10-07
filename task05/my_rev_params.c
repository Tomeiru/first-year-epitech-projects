/*
** EPITECH PROJECT, 2020
** my_print_params
** File description:
** my_print_params
*/

void charprint(char c)
{
    write(1, &c, 1);
}

int printer(char const *str)
{
    int l = 0;

    while (str[l] != '\0') {
        charprint(str[l]);
        l = l + 1;
    }
    charprint('\n');
}


void my_rev_params(int nbarg, char **args)
{
    nbarg = nbarg - 1;
    while (nbarg != -1) {
        printer(args[nbarg]);
        nbarg--;
    }
}