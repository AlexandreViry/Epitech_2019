/*
** EPITECH PROJECT, 2019
** my_int_to_str.C
** File description:
** we put int into an str
*/

#include "./my.h"
int dec_int_to_str(int nb, int n)
{
    for (int x = 0; x != n; x++)
        nb = nb / 10;
    return (nb);
}

int num_len_str_to_int(int nb)
{
    int x;
    for (x = 0; nb > 9; x++) {
        nb = nb / 10;
    }
    return (x);
}


char *my_int_to_str(char *str, int nb)
{
    int temp = nb;
    int y = 0;
    int len = num_len_str_to_int(nb);
    for (int x = len; x != -1; x--) {
        temp = dec_int_to_str(nb, x) % 10;
        str[y] = temp + '0';
        y = y + 1;
    }
    return (str);
}
