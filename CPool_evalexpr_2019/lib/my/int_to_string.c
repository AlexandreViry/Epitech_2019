/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/
#include <stdlib.h>

char *my_revstr(char *str);

char *int_to_string(int nb)
{
    int y = 0;
    int x = 0;
    char c;
    char *str = malloc(sizeof(char) * nb);
    int z = 0;
    
    while (nb > 0) {
        z = nb % 10;
        c = z + 48;
        str[x] = c;
        x = x + 1;
        nb = nb / 10;
    }
    str = my_revstr(str);
    return (str);
}
