/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr (char const *str)
{
    long number = 0; 
    int pos = 1;
    int l = 0;

    while (str[l] == '-' || str[l] == '+'){
        if (str[l] == '-') {
            pos = pos * -1;
        }
        l++;
    }
    while (str[l] >= '0' && str[l] <= '9') {
        number = number * 10;
        number = number + str[l] - '0';
        l++;
    }
    number = number * pos;
    if (number > 2147483647 || number < -2147483547) {
        return (0);
    }
    return((int)number);
}
