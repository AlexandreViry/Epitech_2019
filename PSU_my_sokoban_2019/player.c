/*
** EPITECH PROJECT, 2020
** player
** File description:
** player functions
*/

#include "include/my.h"

int how_many(int nb, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == 'O')
            nb++;
    return (nb);
}

char **set_o(char **map, int *coo)
{
    for (int y = 0; coo[y] != 0;) {
        if (map[coo[y]][coo[y + 1]] == ' ') {
            map[coo[y]][coo[y + 1]] = 'O';
        }
        y = y + 2;
    }
    return (map);
}

int *is_it_O(char **map, int i, int x, int *coo_o)
{
    int y = 0;

    if (map[i][x] == 'O') {
        for (; coo_o[y] != 0; y++) {
        }
        coo_o[y] = i;
        coo_o[y + 1] = x;
        coo_o[y + 2] = 0;
    }
    return (coo_o);
}

int *where_is_O(char **map)
{
    int i = 0;
    int x = 0;
    int nb = 0;
    int *coo_o;

    for (; map[i] != NULL; i++)
        nb = how_many(nb, map[x]);
    coo_o = malloc(sizeof(int) * nb * 2 + sizeof(int));
    i = 0;
    x = 0;
    for (; map[i] != NULL; i++) {
        for (;map[i][x] != '\0'; x++)
            coo_o = is_it_O(map, i, x, coo_o);
            x = 0;
    }
    return (coo_o);
}

int *search_p(char **map)
{
    int x = 0;
    int y = 0;
    for (int i = 0; map[y][x] != 'P'; i++) {
        if (map[y][x] == '\n') {
            y++;
            x = 0;
        }
        x++;
    }
    int *coo = malloc(sizeof(int) * 2);
    coo[0] = y;
    coo[1] = x;
    return (coo);
}
