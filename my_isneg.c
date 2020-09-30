/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** Function that displays either N if the interger passed as negative, P if positive or null
*/

int     my_isneg(int n)
{
    char N = 'N';
    char P = 'P';
        
    if (n >= 0) {
        my_putchar(P);
    }

    else {
        my_putchar(N);
    }
}
