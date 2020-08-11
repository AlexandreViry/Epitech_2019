/*
** EPITECH PROJECT, 2019
** my_put_long
** File description:
** print a long
*/

#include <unistd.h>
int my_put_nbr(int nb);
void my_putchar(char c);

int my_put_long(long nb)
{
    if (nb < 0)
    {
        my_putchar(45);
        nb = nb * -1;
    }
    if (nb < 10)
        my_putchar(nb + 48);
    else
    {
        int c;
        nb = nb / 10;
        my_putchar(nb + 48);
        c = nb % 10;
        my_put_nbr(nb);
        my_putchar(c + 48);
    }
    return (0);
}
