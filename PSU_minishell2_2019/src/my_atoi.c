/*
** EPITECH PROJECT, 2019
** my_atoi.c
** File description:
** convert a string into an int
*/

#include "my.h"

int my_atoi(char *str)
{
    int i = 0;
    int nb0;
    int nb1 = 0;

    if (str[i] == '-')
        i++;
    while (str[i] != '\0' || str[i] != '\n') {
        nb1 = nb1 * 10;
        nb0 = str[i] - 48;
        if (nb0 < 0 || nb0 > 9) {
            nb1 = nb1 / 10;
            return (nb1);
        }
        nb1 = nb1 + nb0;
        i++;
    }
    if (str[0] == '-')
        nb1 *= (-1);
    return (nb1);
}

int my_get_nbr(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        nb = str[i];
        if (nb == '-')
            return (0);
        if (nb > '0' && nb <= '9')
            return (nb);
    }
    return (0);
}
