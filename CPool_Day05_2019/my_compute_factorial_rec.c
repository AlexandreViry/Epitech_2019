/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec.c
** File description:
** Write a recursive function for number given.
*/

#include <stdio.h>

int my_compute_factorial_rec(int nb)
{
    if (nb >= 13) {
        printf("The factorial of %d is bigger than %d.\n", nb, INT_MAX);
        return 0;
    }
    if (nb < 0) {
        printf("The value must be a positive integer.\n");
        return 0;
    }
    if (nb == 0 || nb == 1)
        return 1;
    else
        return (nb * my_compute_factorial_rec (nb-1));
}

int main(void)
{
    int res;

    res = my_compute_factorial_rec(7);
    //@ assert res == 5040;
    res = my_compute_factorial_rec(13);
    //@ assert res == 0;
    res = my_compute_factorial_rec(12);
    //@ assert res == 479001600;
    res = my_compute_factorial_rec(2);
    //@ assert res == 2;
    res = my_compute_factorial_rec(-4);
    //@ assert res == 0;
    res = my_compute_factorial_rec(3);
    //@ assert res == 6;
    return 0;
}
