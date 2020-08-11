/*
** EPITECH PROJECT, 2019
** my_print-digits.c
** File description:Write a function that displays all the digits, on a single line, in ascending order.
*/

#include<unistd.h>

void my_putchar (char c);

int my_print_digits(void)
{
    int d;
    
    d = 48;
    while (d <= 57)
    {
        my_putchar(d);
        d = d + 1;
    }
    return(0);
}
