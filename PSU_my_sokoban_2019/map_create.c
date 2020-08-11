/*
** EPITECH PROJECT, 2020
** map create
** File description:
** creation of the map
*/

#include "include/my.h"

char **convert(char *buff, char **map)
{
    int x = 0;
    int i = 0;

    for (int y = 0; buff[y] != '\0'; y++) {
        map[x][i] = buff[y];
        if (buff[y] == '\n') {
            x++;
            i = 0;
        } else
            i++;
    }
    return (map);
}

int how_many_lines(char *buff)
{
    int y = 0;

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n')
            y++;
    }
    return (y);
}

int count_char(char *buff)
{
    static int count = 0;
    int i = 0;

    if (buff[count] == '\n')
        count++;
    while (buff[count] != '\0') {
        if (buff[count] == '\n')
            return (i);
        count++;
        i++;
    }
    return (i);
}

char **map_create(char *filepath)
{
    struct stat sb;
    int fd = open(filepath, O_RDONLY);
    stat(filepath, &sb);
    char *buff = malloc(sizeof(char) * (int)sb.st_size + 1);
    char **map;

    read(fd, buff, sb.st_size);
    close(fd);
    map = malloc(sizeof(char *) * how_many_lines(buff) + 1);
    for (int i = 0; i != how_many_lines(buff) + 1; i++)
        map[i] = malloc(sizeof(char) * count_char(buff) + 1);
    map = convert(buff, map);
    return (map);
}

int the_longest(char *buff, int lines)
{
    int i = 0;
    int y = 0;
    int z = 0;

    while (y != lines) {
        while (buff[i] != '\n')
            i++;
        if (i <= z)
            z = i;
        y++;
    }
    return (z);
}