/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** transform str to int
*/

#include "my.h"
int str_to_nb(char const *str, int n)
{
    int dec = 10;
    int nb = 0;
    int i = n;
    int len;
    int c = n;
    len = my_strlen(str);
    while (str[n] != '\0') {
        if (str[n] <= '9' && str[n] >= '0') {
            i = i + 1;
            n = n + 1;
        } else {
            n = len;
        }
    }
    len = i - c - 1;
    dec = my_compute_power_rec(dec, len);
    for (int z = c; z != i; z++) {
        nb = (str[z] - '0') * dec + nb;
        dec = dec / 10;
    }
    return (nb);
}

int nb_is_neg(char const *str, int j, int nb)
{
    if (str[0] == '-') {
        nb = nb * (-1);
    }
    if (str[j - 1] == '-') {
        if (str[j - 2] == '+' || str[j - 2] == '-') {
            nb = nb * (-1);
        }
        if (str[j - 2] == '*' || str[j - 2] == '/' || str[j - 2] == '%') {
            nb = nb * (-1);
        }
    }
    return (nb);
}

int str_to_int_red(char const *str)
{
    int nb = 0;
    int i = 0;
    int j = 0;
    int len;
    len = my_strlen(str);
    while (str[i] != '\0') {
        if (str[i] > '9' || str[i] < '0') {
            i = i + 1;
        } else {
            j = i;
            i = len;
        }
    }
    nb = str_to_nb(str, j);
    nb = nb_is_neg(str, j, nb);
    return (nb);
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            len = len + 1;
        }
    }
    if (len >= 10) {
        return (0);
    } else {
        nb = str_to_int_red(str);
    }
    return (nb);
}
