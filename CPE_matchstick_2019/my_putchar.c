/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** displays a char
*/

#include <unistd.h>
#include "my.h"

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

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}
