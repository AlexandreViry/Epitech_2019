/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description:
** Write a function that swaps the content of two integers, whose addresses are given as a parameter.
*/

void my_swap(int *a , int *b)
{
    int c;
    
    c = *a;
    *a = *b;
    *b = c;
}
    
