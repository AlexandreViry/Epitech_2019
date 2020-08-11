/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** display a string
*/

#include <unistd.h>
#include <stdlib.h>
void my_putchar(char c)
{
    write (1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
