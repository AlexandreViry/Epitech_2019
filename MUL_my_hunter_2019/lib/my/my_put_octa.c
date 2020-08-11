/*
** EPITECH PROJECT, 2019
** my_put_hexa
** File description:
** displays with hecta base
*/

#include <unistd.h>

int my_put_octa(int nb);
void my_putchar(char c);

int for_octa_bigger(int nb)
{
    int c;
    c = nb;
    nb = nb / 8;
    c = c % 8;
    my_put_octa(nb);
    my_put_octa(c);
    return (c);
}

int my_put_octa(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    if  (nb < 10) { 
        my_putchar(nb + 48);
    } else {
        for_octa_bigger(nb);
    }
    return (0);
}
