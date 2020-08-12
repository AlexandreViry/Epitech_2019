/*
** EPITECH PROJECT, 2019
** my_print_revalpha.c
** File description:
**
*/

#include <stdio.h>

int my_print_revalpha(void)
{
    for (char a = 122; a >= 97; a--)
        printf("%c", a);
    printf("\n");
    return 0;
}

int main(void)
{
    my_print_revalpha();
    return 0;
}
