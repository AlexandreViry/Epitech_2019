/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Write a function that displays, one-by-one, the characters of a string
*/

#include <stdio.h>

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        printf("%c", str[i]);
    return 0;
}

int main(void)
{
    my_putstr("coucou toi\n");
    return 0;
}
