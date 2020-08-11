 /*
** EPITECH PROJECT, 2019
** my_copy_segment;
** File description:
** copy a string from a to b
*/

#include <stdlib.h>
#include "my.h"
char *my_copy_segment(char *str, char *dest, int a, int b)
{
    int len;
    int i = 0;
    len = b - a;
    while (i != len) {
        dest[i] = str[a];
        a = a + 1;
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
