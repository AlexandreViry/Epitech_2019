/*
** EPITECH PROJECT, 2019
** my_print-digits.c
** File description:Write a function that displays all the digits.
*/

#include <stdio.h>

int my_print_digits(void)
{
    for (char digit = '0'; digit <= '9'; digit++)
        printf("%c", digit);
    printf("\n");
    return 0;
}

int my_print_digits2(void)
{
    for (char digit = 48; digit <= 57; digit++)
        printf("%c", digit);
    printf("\n");
    return 0;
}

int main(void)
{
    my_print_digits();
    my_print_digits2();
    return 0;
}
