/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** my_str_isalpha
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    int count = 0;
    
    while(str[i] != '\0') {
        if (str[i] < 48 && str[i] > 57)
            count++;
        i++;
    }
    if (i == 0 || count == 0)
        return (1);
    else
        return (0);
}