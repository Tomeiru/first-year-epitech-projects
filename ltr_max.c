/*
** EPITECH PROJECT, 2020
** ltr_max
** File description:
** ltr_max
*/

int my_ltr_isalpha(char ltr)
{
    int i = 0;
    int count = 0;

    if (ltr < 65 || ltr > 122 || ltr <= 96 && ltr >= 91)
        count++;
    if (count == 0)
        return (1);
    else
        return (0);
}

int ltr_max (char **av)
{
    int count = 0;

    for (int i = 0; av[1][i]; ++i) {
        if (my_ltr_isalpha(av[1][i]) == 1)
            count++;
    }
    return (count);
}