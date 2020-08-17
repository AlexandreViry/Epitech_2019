/*
** EPITECH PROJECT, 2019
** my_print-digits.c
** File description:Write a function that displays all the digits.
*/

#include <stdio.h>

/*
** Displaying all digits in ascending order, using the character of numbers
** for the loop.
*/

int my_print_digits(void)
{
    for (char d = '0'; d <= '9'; d++)
        printf("%c", d);
    printf("\n");
    return 0;
}

/*
** Displaying all digits in ascending order, using the ASCII value of numbers
** for the loop.
*/

int my_print_digits2(void)
{
    for (char d = 48; d <= 57; d++)
        printf("%c", d);
    printf("\n");
    return 0;
}

int main(void)
{
    my_print_digits();
    my_print_digits2();
    return 0;
}
