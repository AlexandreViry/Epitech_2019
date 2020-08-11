/*
** EPITECH PROJECT, 2020
** recup
** File description:
** take the coo given by the signals
*/

#include "include/my.h"

int recup(int y)
{
    static int final;
    static int res;
    static int count = 0;

    if (count == 2) {
        count = 0;
        final = res + 100;
        res = 0;
        return (final);
    }
    if (y == 0) {
        res = res * 10;
        count++;
    }
    else if (y == 1)
        res++;
}