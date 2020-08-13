/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** allocate memories and copies.
*/

#include <stdlib.h>
#include <string.h>

char *my_strdup(char const *src)
{
    char *str;
    int src_len = strlen(src);

    str = malloc(str_len + 1);
    for (int count = 0; src[count] != '\0'; count++)
        str[count] = src[count];
    str[src_len] = '\0';
    return str;
}

int main(void)
{
    char *string;
    int res;

    string = my_strdup("youpi!!");
    res = strcmp(string, "youpi!!");
    //@ assert res == 0;
    return 0;
}
