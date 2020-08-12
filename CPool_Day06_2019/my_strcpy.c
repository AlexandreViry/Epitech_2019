/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** copy and past a string
*/

#include <stdio.h>
#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; src[i] != '\0'; ++i)
        dest[i] = src[i];
    return (dest);
}

int main(void)
{
    char *res = malloc(sizeof(char) * 6);

    res = my_strcpy(res, "salut");
    //@ assert res == "salut";
    return 0;
}
