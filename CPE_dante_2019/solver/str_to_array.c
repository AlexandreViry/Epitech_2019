/*
** EPITECH PROJECT, 2020
** str_to_array
** File description:
** convert a string into an array
*/

#include "include/fcts.h"

int *lines(char *str)
{
    int len = my_strlen(str);
    int *size = malloc(sizeof(int) * 2);
    int lines = 0;
    int col = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] == '\n')
            lines++;
    }
    for (; str[col] != '\n'; col++){
    }
    size[0] = lines + 2;
    size[1] = col + 1;
    if (str[len - 1] != '\n')
        size[0] = size[0] + 1;
    return (size);
}

char **map_create(char *buff, int *size)
{
    char **map = malloc(sizeof(char *) * (size[0] + 1));
    int x = 0;
    int y = 0;

    for (int i = 0; i != size[0]; i++)
        map[i] = malloc(sizeof(char) * (size[1] + 1));
    map[size[0]] = NULL;
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            map[x][y] = '\0';
            x++;
            y = 0;
        } else {
            map[x][y] = buff[i];
            y++;
        }
    }
    map[x][y] = '\0';
    map[size[0]] = NULL;
    return (map);
}

char **sgl_to_dbl(char *path)
{
    int fd = open(path, O_RDONLY);
    struct stat sb;
    int *size;
    char **map;
    char *buff;

    if (fd == -1)
        exit(84);
    stat(path, &sb);
    buff = malloc((int)sb.st_size);
    if (read(fd, buff, (int)sb.st_size) == -1)
        exit(84);
    buff[(int)sb.st_size - 1] = '\0';
    size = lines(buff);
    map = map_create(buff, size);
    return (map);
}
