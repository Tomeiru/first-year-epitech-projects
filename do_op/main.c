/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "doop.h"

int main(int argc, char **argv) 
{
    if (error(argc, argv) == 85)
        return(84);
    if (error(argc, argv) == 84) {
        my_putchar('0');
        my_putchar('\n');
        return(84);
    }
    my_put_nbr(doop(argc, argv));
}
