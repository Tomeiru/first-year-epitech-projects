/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    int i = 0;

    if (str[i] >= 97 && str[i] <= 122) {
        str[i] = str [i] - 32;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            if (str[i - 1] != ' ' || str[i - 1] != '+' || str[i - 1] != '-')
                str[i] = str[i] + 32;
        if (str[i] >= 97 && str[i] <= 122)
            if (str[i - 1] == ' ' || str[i - 1] == '+' || str[i - 1] == '-')
                str[i] = str[i] - 32;
    i++;
    }
    return (str);
}