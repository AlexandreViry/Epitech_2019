/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
**
*/

#include <stdlib.h>
#include <stdio.h>

/*
** Displays and return the number of characters of the string sent
** in parameter by using a 'for' loop.
*/

int my_strlen(const char *str)
{
    int i;

    if (str == NULL) {
        printf("Error: 'str' is a NULL pointer\n");
        return -1;
    }
    for (i = 0; str[i] != '\0'; i++);
    printf("Length of '%s' == %d.\n", str, i);
    return i;
}

/*
** Displays and return the number of characters of the string sent
** in parameter by using a 'while' loop.
*/

int my_strlen2(const char *str)
{
    int i = 0;

    if (str == NULL) {
        printf("Error: 'str' is a NULL pointer\n");
        return -1;
    }
    while (str[i] != '\0')
        ++i;
    printf("Length of '%s' == %d.\n", str, i);
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
