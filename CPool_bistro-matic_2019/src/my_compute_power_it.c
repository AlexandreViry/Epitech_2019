/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** Iterative function that gives the result of the number and the power
** given in parameter.
*/

#include <limits.h>
#include <stdio.h>

int my_compute_power_it(int nb , int p)
{
    int res = nb;
    int tmp = p;

    if (tmp < 0)
        return 0;
    if (tmp == 0)
        return 1;
    for (; tmp > 1; tmp--) {
        if (INT_MAX / res <= nb && INT_MAX / res > 0)
            return 0;
        res = nb * res;
    }
    return res;
}
