/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** write the number
*/
#include <unistd.h>

void my_putchar(char c);

int my_put_nbr (int nb)
{
    if (nb < 0)
    {
        my_putchar(45);
        nb = nb * -1;
    }
    if (nb < 10)
    {
        my_putchar(nb + 48);
    }
    else
    {
        int c;
        c = nb;
        nb = nb / 10;
        my_putchar(nb + 48);
        c = c % 10;
        my_putchar(c + 48);
    }
    return(0);
}

