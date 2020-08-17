/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** displays the lowercase alphabet in ascending order, on a single line.
*/

#include <stdio.h>

/*
** Displaying the alphabet with letter and ASCII values of the letters
** and a 'while' loop.
*/
int my_print_alpha1(void)
{
    char c = 97;

    while (c <= 122) {
        printf("%c", c);
        c = c + 1;
    }
    printf("\n");
    return 0;
}

/*
** Displaying the alphabet with letter and ASCII values of the letters
** and a 'for' loop.
*/

int my_print_alpha2(void)
{
    for (char c = 97; c <= 122; c++)
        printf("%c", c);
    printf("\n");
    return 0;
}

/*
** Displaying the alphabet with the char values of the letters
** and a 'for' loop.
*/

int my_print_alpha3(void)
{
    for (char c = 'a'; c <= 'z'; c++)
        printf("%c", c);
    printf("\n");
    return 0;
}

int main(void)
{
    my_print_alpha1();
    my_print_alpha2();
    my_print_alpha3();
    return 0;
}
