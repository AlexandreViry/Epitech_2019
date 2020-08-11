/*
** EPITECH PROJECT, 2019
** my_strcapitalize.c
** File description:
** we put in caps the first letter of each word
*/

#include "my.h"
char *my_strcapitalize(char *str)
{
    int n = 0;
    my_strlowcase(str);
    while (str[n] != '\0') {
        if (str[n] <= 'a' && str[n] >= 'z') {
            my_putchar('1');
            n++;
            if (str[n] >= 'a' && str[n] <= 'z') {
                my_putchar('2');
                str[n] = str[n] - 32;
                n++;
            } else {
                my_putchar('3');
                n++;
            }
        } else {
            n++;
        }
        n++;
    }
    return (str);
}
