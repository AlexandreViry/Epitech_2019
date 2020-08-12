/*
** EPITECH PROJECT, 2019
** my_isneg.c
** File description:
**
*/

#include <stdio.h>

int my_isneg(int n)
{
    if (n < 0) {
        printf("N\n");
        return 0;
    }
    else {
        printf("P\n");
        return -1;
    }
}

int main(void)
{
    int i;

    i = my_isneg(-13);
    //@ assert i == 0;
    i = my_isneg(42);
    //@ assert i == -1;
    return 0;
}
