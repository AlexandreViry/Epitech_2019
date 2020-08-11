/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** return le nombre de caractere dans le string donner
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
