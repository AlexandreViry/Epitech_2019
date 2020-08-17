/*
** EPITECH PROJECT, 2019
** my_compute_power_rec
** File description:
** Recursive function that returns the result of the number and the power given
** in parameter.
*/

#include <stdio.h>
#include <limits.h>

int my_compute_power_rec(int n , int p)
{
    int res = n;
    static int init_p = 0;

    if (p < 0) {
        printf("P value must be greater than or equal to 0\n");
        return 0;
    }
    if (p == 0) {
        printf("The value of n to the power of 0 is always 1.\n");
        return 1;
    }
    if (INT_MAX / res <= n && INT_MAX / res > 0) {
        printf("%d to the power of %d produces a signed overflow\n", n, p + init_p);
        return 0;
    }
    if (p > 1) {
        init_p++;
        res = n * my_compute_power_rec(n, p - 1);
        if (p == init_p) {
            printf("%d to the power of %d == %d\n", n, init_p, res);
            init_p = 0;
        }
        return res;
    }
    init_p++;
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
