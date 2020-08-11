/*
** EPITECH PROJECT, 2019
** my_put_binary
** File description:
** display the binary of an int
*/

#include <unistd.h>
#include <stdlib.h>
#include "../../include/my.h"

int for_binary_bigger(int nb)
{
    int c;

    c = nb;
    nb = nb / 2;
    c = c % 2;
    my_put_binar(nb);
    my_put_binar(c);
    return (c);
}

int my_put_binar(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    if  (nb < 2) {
        my_putchar(nb + 48);
    } else {
        for_binary_bigger(nb);
    }
    return (0);
}
