/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec.c
** File description:
** Write a recursive function for number given.
*/

#include <stdio.h>
#include <limits.h>

int my_compute_factorial_rec(int n)
{
    static int last = 0;
    int res = 1; // factorial(0) == 1 and factorial(1) == 1.

    if (n < 0) {
        printf("Cannot compute fact(%d). "
               "The argument must be a positive integer.\n", n);
        return 0;
    }
    if (n >= 13) {
        printf("Factorial(%d) is bigger than %d "
               "and produces a signed overflow\n", n, INT_MAX);
        return 0;
    }
    if (n > 1) {
        last++;
        res = n * my_compute_factorial_rec(n - 1);
    }
    if (last == n) {
        printf("Factorial(%d) == %d\n", n, res);
        last = 0;
    }
    return res;
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
