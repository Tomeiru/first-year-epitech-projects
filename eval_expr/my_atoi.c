/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** takes number from string
*/

int my_atoi(char *str)
{
    int nbr = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= '0' && str[i] <= '9')
            nbr = nbr * 10 + str[i] - 48;
    return (nbr);
}