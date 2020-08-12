/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string
*/

#include <stdlib.h>
#include <stdio.h>

char *my_revstr(char *str) {

    int i = 0;
    char *tmp;
    int y = 0;

    for (;str[i] != '\0'; i++);
    tmp = malloc(sizeof(char) * (i + 1));
    i--;
    for (; i >= 0; y++, i--)
        tmp[y] = str[i];
    return tmp;
}

int main(void)
{
    char *res;

    res = my_revstr("salut");
    //@ assert res == "tulas";
    res = my_revstr("a");
    //@ assert res == "a";
    res = my_revstr("");
    //@ assert res == "";
    return 0;
}
