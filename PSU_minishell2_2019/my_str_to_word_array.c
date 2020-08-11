/*
** EPITECH PROJECT, 2020
** str to word array
** File description:
** convert a string into a strig array
*/

#include "include/my.h"

int index_1(char *str, char c)
{
    int i = 1;

    for (int y = 0; str[y] != '\0' && str [y] != '\n'; y++) {
        if (str[y] == c)
            i++;
    }
    return i;
}

char **create_array(char *str, char c)
{
    int i = 0;
    int z = 0;
    char **array = malloc(sizeof(char *) * (index_1(str, c) + 2));

    for (int y = 0; str[y] != '\0'; y++, z++) {
        if (str[y] == '\n')
            break;
        if (str[y] == c) {
            array[i] = malloc(sizeof(char) * (z + 1));
            z = 0;
            i++;
            y++;
        }
    }
    array[i] = malloc(sizeof(char) * (z + 1));
    array[i + 1] = NULL;
    return (array);
}

char **my_str_to_word_array(char *str, char c)
{
    int y = 0;
    int z = 0;
    char **array = create_array(str, c);

    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++, z++) {
        if (str[i] == c) {
            array[y][z] = '\0';
            y++;
            z = -1;
            continue;
        }
        array[y][z] = str[i];
    }
    array[y][z] = '\0';
    return (array);
}