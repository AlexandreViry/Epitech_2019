/*
** EPITECH PROJECT, 2019
** my_print_revalpha.c
** File description:
**
*/

#include <stdio.h>

int my_print_revalpha(void)
{
    for (char letter = 122; letter >= 97; letter--)
        printf("%c", letter);
    printf("\n");
    return 0;
}

int my_print_revalpha2(void)
{
    for (char letter = 'z'; letter >= 'a'; letter--)
        printf("%c", letter);
    printf("\n");
    return 0;
}

int main(void)
{
    my_print_revalpha();
    my_print_revalpha2();
    return 0;
}
