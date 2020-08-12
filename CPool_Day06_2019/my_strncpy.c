/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copiesncharacters from a string into another.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *my_strncpy(char *dest, char const *src , int n)
{
    int y = strlen(src);

    if (y < n) {
        printf("Not enough char in src for n.\n");
        return NULL;
    }
    for (int i  = 0; i != n && i < y; ++i)
        dest[i] = src[i];
    return (dest);
}

int main(void)
{
    char *res = malloc(sizeof(char) * 6);
    int cmp;

    res = my_strncpy(res, "salut à tous", 5);
    cmp = strcmp(res, "salut");
    //@ assert cmp == 0;
    return 0;
}
