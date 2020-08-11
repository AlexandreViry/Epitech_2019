/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** We Put nb
*/

#include "my.h"
#include <stdio.h>
int num_length(int nb)
{
    int x;
    for (x = 0; nb > 9; x++) {
        nb = nb / 10;
    }
    return (x);
}

int decimal(int nb, int n)
{
    for (int x = 0; x != n; x++)
        nb = nb / 10;
    return (nb);
}

void print_nbr_pos(int nb)
{
    int temp = nb;
    int length = num_length(nb);
    
    for (int x = length; x != -1; x--) {
        temp = decimal(nb, x) % 10;
        my_putchar(temp + '0');
    }
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
        print_nbr_pos(nb);
    } else {
        print_nbr_pos(nb);
    }
    return (0);
}
