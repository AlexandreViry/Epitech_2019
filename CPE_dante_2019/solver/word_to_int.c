/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** word_to_int
*/

#include "include/fcts.h"

int my_strlen(char *str)
{
    int sz = 0;

    while (str[sz] != '\0')
        sz++;
    return sz;
}

int my_tablen(char **array)
{
    int sz = 0;

    while (array[sz] != NULL)
        sz++;
    return sz;
}

int make_arr_elem(char **tab, int i, int j)
{
    if (tab[i][j] == 'X')
        return -1;
    else
        return 0;
}

int **word_to_int_array(char **words)
{
    int **array;
    int string_length = my_strlen(words[0]);
    int tab_len = my_tablen(words) - 1;

    array = malloc(sizeof(int *) * (tab_len));
    for (int i = 0;  i < (tab_len); i++)
        array[i] = malloc(sizeof(int) * string_length);
    for (int i = 0; i < tab_len - 1; i++) {
        for (int j = 0; j < string_length; j++) {
            array[i][j] = make_arr_elem(words, i, j);
        }
    }
    array[tab_len - 1] = NULL;
    return array;
}
