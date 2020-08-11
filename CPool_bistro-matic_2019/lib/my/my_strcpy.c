/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** We copie strings
*/

void copie_str(char *dest, char const *src)
{
    int j = 0;

    while (src[j] != '\0') {
        dest[j] = src[j];
        j = j + 1;
    }
}

char *my_strcpy(char *dest, char const *src)
{
    copie_str(dest, src);
    return (dest);
}
