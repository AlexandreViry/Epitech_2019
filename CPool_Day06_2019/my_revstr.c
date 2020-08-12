/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** reverse a string
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *my_revstr(char *str) {

    int len_str = 0;
    char *tmp;
    int y = 0;

    len_str = strlen(str);
    tmp = malloc(sizeof(char) * (len_str + 1));
    len_str--;
    for (; len_str >= 0; y++, len_str--)
        tmp[y] = str[len_str];
    tmp[y] = '\0';
    return tmp;
}

int main(void)
{
    char *res;
    int cmp;

    res = my_revstr("salut");
    printf("%s\n", res);
    cmp = strcmp(res, "tulas");
    //@ assert cmp == 0;
    res = my_revstr("a");
    cmp = strcmp(res, "a");
    //@ assert cmp == 0;
    res = my_revstr("");
    cmp = strcmp(res, "");
    //@ assert cmp == 0;
    return 0;
}
