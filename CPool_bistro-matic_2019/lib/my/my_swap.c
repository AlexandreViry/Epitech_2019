/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description:
** We swap integer YES
*/

#include "my.h"
void my_swap(int *a, int *b)
{
    int int1;
    int int2;
    int temp;

    int1 = *a;
    int2 = *b;
    *a = int2;
    *b = int1;
}
