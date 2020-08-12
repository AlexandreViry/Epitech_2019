/*
** EPITECH PROJECT, 2019
** my_print-digits.c
** File description:Write a function that displays all the digits.
*/

#include <stdio.h>

int my_print_digits(void)
{
    for (char d = '0'; d <= '9'; d++)
        printf("%c", d);
    printf("\n");
    return 0;
}

int main(void)
{
    my_print_digits();
    return 0;
}
