/*
** EPITECH PROJECT, 2019
** my_compute_power_it
** File description:
** iterative function
*/

#include <limits.h>
#include <stdio.h>

int my_compute_power_it(int nb , int p)
{
    int res = nb;

    if (p < 0) {
        printf("P value must be greater than or equal to 0");
        return 0;
    }
    if (p == 0)
        return 1;
    for (; p > 1; p--) {
        if (INT_MAX / res <= nb && INT_MAX / res > 0)
            return 0;
        res = nb * res;
    }
    return res;
}

int main(void)
{
    int res;

    res = my_compute_power_it(7, -1);
    //@ assert res == 0;
    res = my_compute_power_it(6, 0);
    //@ assert res == 1;
    res = my_compute_power_it(10, 5);
    //@ assert res == 100000;
    res = my_compute_power_it(2, 2);
    //@ assert res == 4;
    res = my_compute_power_it(-4, 4);
    //@ assert res == 256;
    res = my_compute_power_it(6, 1);
    //@ assert res == 6;
    res = my_compute_power_it(10000000, 10);
    //@ assert res == 0;
    return 0;
}
