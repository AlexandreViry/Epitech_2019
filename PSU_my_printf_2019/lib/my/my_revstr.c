/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** return a string
*/

char *my_revstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    while (i != 0) {
        i = i--;
    }
    return (str);
}
