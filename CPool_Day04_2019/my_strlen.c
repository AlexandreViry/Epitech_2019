/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
**
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i;

    if (str == NULL)
        return -1;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int my_strlen2(char const *str)
{
    int i = 0;

    if (str == NULL)
        return -1;
    while (str[i] != '\0')
        ++i;
    return i;
}

int main(void)
{
    int i = 0;

    i = my_strlen("coucou toi");
    //@ assert i == 10;
    i = my_strlen("segfault");
    //@ assert i == 8;
    i = my_strlen("");
    //@ assert i == 0;
    i = my_strlen(NULL);
    //@ assert i == -1;
    i = my_strlen2("coucou toi");
    //@ assert i == 10;
    i = my_strlen2("segfault");
    //@ assert i == 8;
    i = my_strlen2("");
    //@ assert i == 0;
    i = my_strlen2(NULL);
    //@ assert i == -1;
    return 0;
}
