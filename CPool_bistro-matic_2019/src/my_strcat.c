/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Function that contatenate two strings and returns 'dest'.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat (char *dest, char const *src) {

    int size_src = strlen(src);
    int size_dest = strlen(dest);
    int end_of_line = size_src + size_dest + 1;
    char *res = malloc(end_of_line);
    int tmp = 0;

    for (int i = 0; i < size_dest; i++)
        res[i] = dest[i];
    for (int i = size_dest; src[tmp] != '\0'; i++, tmp++)
        res[i] = src[tmp];
    res[end_of_line - 1] = '\0';
    return(res);
}
