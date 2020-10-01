/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** my_put_nbr
*/

int     my_put_nbr(int nb)
{
    int div;
    div = 1;
    if (nb < 0){
        put_char('-');
        nb*=-1;
    }
    while ((nb/div) >= 10){
        div/=10;
    }       
    while ((nb/div) <= 10){
        (nb/div % 10 + '0');
    }     
            
    return(0);
}   
                        
      
