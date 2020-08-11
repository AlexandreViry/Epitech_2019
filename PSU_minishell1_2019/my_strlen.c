/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** count char of a string
*/

int my_strlen(char *str)
{
    int i = 0;
    
    while (str[i] != '\n' || str[i] != '\n')
        i++;
    return (i);
}

int my_strlen2(char *str, int i)
{
    int y = 0;

    for (; str[i] != '\n'; y++) {
        if (str[i] == '\0')
            return (y);
        if (str[i] == ' ')
            return (y);
        i++;
    }
    return (y);
}

