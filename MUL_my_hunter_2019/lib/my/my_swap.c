/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swap a to b and b to a.
*/

void my_swap(int *a , int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
