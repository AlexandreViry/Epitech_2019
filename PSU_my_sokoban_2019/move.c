/*
** EPITECH PROJECT, 2019
** move
** File description:
** move thanks to a direction
*/

#include "./include/my.h"
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char **move_right(char **map, int *coo)
{
    int y = coo[0];
    int x = coo[1];
    switch (map[y][x + 1]) {
    case '#' :
        return (map);
        break;
    }
    if (map[y][x + 1] == 'X') {
        if (map[y][x + 2] == '#' || map[y][x + 2] == 'X')
            return (0);
        map[y][x + 2] = 'X';
    }
    map[y][x] = ' ';
    map[y][x + 1] = 'P';
    return (map);
}

char **move_left(char **map, int *coo)
{
    int y = coo[0];
    int x = coo[1];
    switch (map[y][x - 1]) {
    case '#' :
        return (map);
        break;
    }
    if (map[y][x - 1] == 'X') {
        if (map[y][x - 2] == '#' || map[y][x - 2] == 'X')
            return (0);
        map[y][x - 2] = 'X';
    }
    map[y][x] = ' ';
    map[y][x - 1] = 'P';
    return (map);
}

char **move_bot(char **map, int *coo)
{
    int y = coo[0];
    int x = coo[1];
    switch (map[y + 1][x]) {
    case '#' :
        return (map);
        break;
    }
    if (map[y + 1][x] == 'X') {
        if (map[y + 2][x] == '#' || map[y + 2][x] == 'X')
            return (0);
        map[y + 2][x] = 'X';
    }
    map[y][x] = ' ';
    map[y + 1][x] = 'P';
    return (map);
}

char **move_top(char **map, int *coo)
{
    int y = coo[0];
    int x = coo[1];
    switch (map[y - 1][x]) {
    case '#' :
        return (map);
        break;
    }
    if (map[y - 1][x] == 'X') {
        if (map[y - 2][x] == '#' || map[y - 2][x] == 'X')
            return (0);
        map[y - 2][x] = 'X';
    }
    map[y][x] = ' ';
    map[y - 1][x] = 'P';
    return (map);
}

char **move_it(char **map, int c, int *coo_o)
{
    int *coo = search_p(map);

    switch (c) {
    case KEY_RIGHT :
        move_right(map, coo);
        break;
    case KEY_LEFT :
        move_left(map, coo);
        break;
    case KEY_UP :
        move_top(map, coo);
        break;
    case KEY_DOWN :
        move_bot(map, coo);
        break;
    }
    map = set_o(map, coo_o);
    return (map);
}