/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** affiche le nombre entrer
*/
#include <unistd.h>

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int x;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }

    if (nb >=10) {
        x = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(x + 48);
    }
    
    else {
        my_putchar(nb + 48);
    }

    return (0);
}
