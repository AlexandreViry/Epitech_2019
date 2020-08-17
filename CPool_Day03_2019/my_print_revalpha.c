/*
** EPITECH PROJECT, 2019
** my_print_revalpha.c
** File description:
**
*/

#include <stdio.h>

/*
** Displaying the alphabet backwards, using the ASCII value of the characters
** for the loop.
*/

int my_print_revalpha(void)
{
    for (char c = 122; c >= 97; c--)
        printf("%c", c);
    printf("\n");
    return 0;
}

/*
** Displaying the alphabet backwards, using the characters for the loop.
*/

int my_print_revalpha2(void)
{
    for (char c = 'z'; c >= 'a'; c--)
        printf("%c", c);
    printf("\n");
    return 0;
}

int main(void)
{
    my_print_revalpha();
    my_print_revalpha2();
    return 0;
}
