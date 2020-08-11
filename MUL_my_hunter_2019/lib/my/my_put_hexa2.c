/*
** EPITECH PROJECT, 2019
** my_put_hexa
** File description:
** displays with hecta base
*/

#include <unistd.h>

int other_case1(int nb);
void my_putchar(char c);

int my_put_hexa2(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    if  (nb < 10) { 
        my_putchar(nb + 48);
    } else {
        other_case1(nb);
    }
    return (0);
}

int other_case2(int nb)
{
    switch (nb) {
    case 13 :
        nb = 100;
        break;
    case 14 :
        nb = 101;
        break;
    case 15:
        nb = 102;
        break;
    }
    return (nb);
}

int for_bigger(int nb)
{
    int c;
    c = nb;
    nb = nb / 16;
    c = c % 16;
    my_put_hexa2(nb);
    my_put_hexa2(c);
    return (c);
}
int other_case1(int nb)
{
    if (nb < 16) {
        switch (nb) {
        case 10 :
            nb = 97;
            break;
        case 11 :
            nb = 98;
            break;
        case 12 :
            nb = 99;
            break;
        default:
            nb = other_case2(nb);
            break;
        }
        my_putchar (nb);
    } else { 
        for_bigger(nb);
    }
}
