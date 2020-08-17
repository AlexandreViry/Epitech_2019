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

    if (tmp < 0) {
        printf("P value must be greater than or equal to 0\n");
        return 0;
    }
    if (tmp == 0)
        return 1;
    for (; tmp > 1; tmp--) {
        if (INT_MAX / res <= nb && INT_MAX / res > 0) {
            printf("%d to the power of %d produces a signed overflow\n", nb, p);
            return 0;
        }
        res = nb * res;
    }
    printf("%d to the power of %d == %d\n", nb, p, res);
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
