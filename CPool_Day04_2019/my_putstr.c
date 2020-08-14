/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Write a function that displays, one-by-one, the characters of a string
*/

#include <stdio.h>

int my_putstr(char const *str)
{
    if (str == NULL) {
        printf("Error: 'str' is a NULL pointer.\n");
        return -1;
    }
    for (int i = 0; str[i] != '\0'; i++)
        printf("%c", str[i]);
    return 0;
}

int my_putstr2(const char *str)
{
    if (str == NULL) {
        printf("Error: 'str' is a NULL pointer.\n");
        return -1;
    }
    while (*str) {
        printf("%c", *str);
        str++;
    }
    return 0;
}

int main(void)
{
    int res;

    res = my_putstr(0);
    //@ assert res == -1;
    res = my_putstr(NULL);
    //@ assert res == -1;
    res = my_putstr("coucou toi\n");
    //@ assert res == 0;
    return 0;
}
