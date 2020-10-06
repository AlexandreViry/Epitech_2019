/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void malloc_error_message(char *function);

char *my_revstr(char *str) {

    int len_str = 0;
    char *tmp;
    int y = 0;

    len_str = strlen(str);
    if ((tmp = malloc(len_str + 1)) == NULL)
        malloc_error_message("my_revstr");
    len_str--;
    for (; len_str >= 0; y++, len_str--)
        tmp[y] = str[len_str];
    tmp[y] = '\0';
    return tmp;
}
