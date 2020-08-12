/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** function that contatenate two strings
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat (char *dest, char const *src) {

    int size_src = strlen(src);
    int size_dest = strlen(dest);
    int end_of_line = size_src + size_dest + 1;

    for (int i = 0; src[i] != '\0'; i++, size_dest++)
        dest[size_dest] = src[i];
    dest[end_of_line - 1] = '\0';
    return(dest);
}

int main(void)
{
    char *dest = malloc(11);
    int res;

    dest = strcpy(dest, "salut");
    dest = my_strcat(dest, "salut");
    printf("%s\n", dest);
    res = strcmp(dest, "salutsalut");
    //@ assert res == 0;
    return 0;
}
