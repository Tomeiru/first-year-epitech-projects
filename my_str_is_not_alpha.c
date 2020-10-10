/*
** EPITECH PROJECT, 2020
** my_str_is_not_alpha
** File description:
** my_str_is_not_alpha
*/

int my_str_isnotalpha(char const *str)
{
    int i = 0;
    int count = 0;
    
    while (str[i] != '\0') {
        if (str[i] < 65 || str[i] > 122 || str[i] <= 96 && str[i] >= 91);
        else
            count++;
        i++;
    }
    if (i == 0 || count == 0)
        return (1);
    else
        return (0);
}