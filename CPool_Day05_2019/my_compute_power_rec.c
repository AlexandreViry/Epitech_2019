/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** recursive function give power
*/

#include <stdio.h>
#include <limits.h>

int my_compute_power_rec(int nb , int p)
{
    int res = nb;

    if (p < 0) {
        printf("P value must be greater than or equal to 0");
        return 0;
    }
    if (p == 0)
        return 1;
    if (INT_MAX / res <= nb && INT_MAX / res > 0)
        return 0;
    if (p > 1)
        res = nb * my_compute_power_rec(nb, p - 1);
    return res;
}

int main(void)
{
    int res;

    res = my_compute_power_rec(7, -1);
    //@ assert res == 0;
    res = my_compute_power_rec(6, 0);
    //@ assert res == 1;
    res = my_compute_power_rec(10, 5);
    //@ assert res == 100000;
    res = my_compute_power_rec(2, 2);
    //@ assert res == 4;
    res = my_compute_power_rec(-4, 4);
    //@ assert res == 256;
    res = my_compute_power_rec(10000000, 12);
    //@ assert res == 0;
    return 0;
}
