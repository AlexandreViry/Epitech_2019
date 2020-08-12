/*
** EPITECH PROJECT, 2019
** my_print_alpha.c
** File description:
** displays the lowercase alphabet in ascending order, on a single line.
*/

#include <stdio.h>

int my_print_alpha1(void)
{
    char a;

    a = 97;
    while (a <= 122) {
        printf("%c", a);
        a = a + 1;
    }
    printf("\n");
    return 0;
}

int my_print_alpha2(void)
{
    for (char a = 97; a <= 122; a++)
        printf("%c", a);
    printf("\n");
    return 0;
}

int my_print_alpha3(void)
{
    for (char a = 'a'; a <= 'z'; a++)
        printf("%c", a);
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
