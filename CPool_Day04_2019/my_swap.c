/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description:
**
*/

void my_swap(int *a , int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void)
{
    int a = 3;
    int b = 8;

    my_swap(&a, &b);
    //@ assert a == 8;
    //@ assert b == 3;
    return 0;
}
