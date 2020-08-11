/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** count char of a string
*/

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_strclen(char *str, char c)
{
    int y = 0;

    for (; str[y] != c; y++)
        if (str[y] == '\0')
            return y;
    return (y);
}

int my_strlen3(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (i);
}

int my_strlen2(char *str, int i)
{
    int y = 0;

    for (; str[i] != '\0'; y++) {
        if (str[i] == '\n')
            return (y);
        if (str[i] == ' ')
            return (y);
        i++;
    }
    return (y);
}
