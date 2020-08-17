/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description: swap the value of two pointers.
**
*/

#include <stdlib.h>
#include <stdio.h>

void my_swap(int *a , int *b)
{
    int tmp;

    if (a == NULL) {
        printf("Error: 'a' is a NULL pointer.\n");
        return;
    }
    if (b == NULL) {
        printf("Error; 'b' is a NULL pointer.\n");
        return;
    }
    tmp = *a;
    *a = *b;
    *b = tmp;
    printf("The values have been correctly "
           "swapped.\na == %d\nb == %d\n", *a, *b);
}

int main(void)
{
    int a = 3;
    int b = 8;

    my_swap(&a, &b);
    //@ assert a == 8;
    //@ assert b == 3;
    my_swap(NULL, &b);
    //@ assert a == 8;
    //@ assert b == 3;
    return 0;
}
