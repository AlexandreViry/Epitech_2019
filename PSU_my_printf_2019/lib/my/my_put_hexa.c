/*
** EPITECH PROJECT, 2019
** my_put_hexa
** File description:
** displays with hecta base
*/

#include <unistd.h>
#include "../../include/my.h"

int my_put_hexa(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    if  (nb < 10) {
        my_putchar(nb + 48);
    } else {
        another_case(nb);
    }
    return (0);
}

int another_case2(int nb)
{
    switch (nb) {
    case 13 :
        nb = 68;
        break;
    case 14 :
        nb = 69;
        break;
    case 15:
        nb = 70;
        break;
    case 16:
        nb = 71;
        break;
    }
    return (nb);
}

int for_bigger1(int nb)
{
    int c;
    c = nb;
    nb = nb / 16;
    c = c % 16;
    my_put_hexa(nb);
    my_put_hexa(c);
    return (c);
}

int another_case(int nb)
{
    if (nb < 16) {
        switch (nb) {
        case 10 :
            nb = 65;
            break;
        case 11 :
            nb = 66;
            break;
        case 12 :
            nb = 67;
            break;
        default:
            nb = another_case2(nb);
            break;
        }
        my_putchar (nb);
    } else {
        for_bigger1(nb);
    }
}
