/*
** EPITECH PROJECT, 2019
** my_replace_char.c
** File description:
** we replace char by another char
*/

#include "my.h"
char *my_replace_char(char *str, char a, char b)
{
    int j = 0;
    while (str[j] != '\0') {
        if (str[j] == a) {
            str[j] = b;
            j = j + 1;
        } else {
            j = j + 1;
        }
    }
    return (str);
}
