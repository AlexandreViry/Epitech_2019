/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it
** File description:
** day 5 task 1.
*/

#include <stdio.h>

int my_compute_factorial_it(int nb)
{
    int y;

    if (nb >= 13) {
        printf("The factorial of this value bigger than INT_MAX.\n");
        return 0;
    }
    if (nb < 0) {
        printf("The value must be a positive integer.\n");
        return 0;
    }
    else if (nb == 1 || nb == 0)
        return 1;
    else {
        for (y = 1; nb > 1; nb = nb - 1)
            y = nb * y;
        return y;
    }
}

int main(void)
{
    int res;

    res = my_compute_factorial_it(7);
    //@ assert res == 5040;
    res = my_compute_factorial_it(13);
    //@ assert res == 0;
    res = my_compute_factorial_it(12);
    //@ assert res == 479001600;
    res = my_compute_factorial_it(2);
    //@ assert res == 2;
    res = my_compute_factorial_it(-4);
    //@ assert res == 0;
    res = my_compute_factorial_it(3);
    //@ assert res == 6;
    return 0;
}
