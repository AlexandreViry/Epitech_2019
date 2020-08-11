/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** print a string
*/

#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}
