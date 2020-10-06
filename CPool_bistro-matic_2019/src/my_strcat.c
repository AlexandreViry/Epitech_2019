/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Function that contatenate two strings and returns 'dest'.
*/

#include "../include/my.h"

char *my_strcat (char *dest, char const *src) {

    int size_src = strlen(src);
    int size_dest = strlen(dest);
    int end_of_line = size_src + size_dest + 1;
    char *res;
    int tmp = 0;

    if ((res = malloc(end_of_line)) == NULL)
        malloc_error_message("my_strcat");
    for (int i = 0; i < size_dest; i++)
        res[i] = dest[i];
    for (int i = size_dest; src[tmp] != '\0'; i++, tmp++)
        res[i] = src[tmp];
    res[end_of_line - 1] = '\0';
    return(res);
}
