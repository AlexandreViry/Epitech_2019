/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** 
*/

char *my_strncpy (char *dest, char const *src ,int n)
{
    int i=0;
    while (i != n) {
        dest[i] = src[i];
        i = i + 1;
    }
    return (dest);
}

