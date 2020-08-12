/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy and past a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcpy(char *dest, char const *src)
{
    int src_str = strlen(src);

    for (int i = 0; src[i] != '\0'; ++i)
        dest[i] = src[i];
    dest[src_str] = '\0';
    return (dest);
}

int main(void)
{
    char *res = malloc(sizeof(char) * 6);
    int cmp;

    res = my_strcpy(res, "salut");
    cmp = strcmp(res, "salut");
    //@ assert cmp = 0;
    return 0;
}
