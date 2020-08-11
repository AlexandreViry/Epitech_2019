/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** write the number
*/

#include <unistd.h>

void my_putchar(char c);
int other_case(int nb);
int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    if  (nb < 10)
        my_putchar(nb + 48);
    else
        other_case(nb);
    return (0);
}

int other_case(int nb)
{
    int c;
    c = nb;
    nb = nb / 10;
    c = c % 10;
    my_put_nbr(nb);
    my_putchar(c + 48);
    return (0);
}
