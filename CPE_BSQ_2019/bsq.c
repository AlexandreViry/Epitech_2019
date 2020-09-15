/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** display the biggest
*/

#include "include/my.h"

typedef struct map {
    char *map;
    int **map_int;
    int size;
} map_t;

void map_without_size(map_t **map)
{
    char *tmp = malloc(strlen((*map)->map) + 1);
    int len = strlen((*map)->map);
    int count;

    strcpy(tmp, (*map)->map);
    for (count = 0; (*map)->map[count] != '\n'; count++);
    count++;
    len = len - count;
    (*map)->map = malloc(len + 1);
    for (int i = 0; tmp[count] != '\0'; count++, i++)
        (*map)->map[i] = tmp[count];
    (*map)->map[len - 1] = '\0';
}

void fill_map(map_t **map)
{
    int x = 0;
    int y = 0;

    for (int i = 0; (*map)->map[i] != '\0'; i++) {
        if ((*map)->map[i] == '\n') {
            x++;
            y = 0;
            continue;
        }
        if ((*map)->map[i] == '.')
            (*map)->map_int[x][y] = 1;
        if ((*map)->map[i] == 'o')
            (*map)->map_int[x][y] = 0;
    }
}

void init_map(char **filepath, map_t *map)
{
    struct stat sb;
    int fd = open(filepath[1], O_RDONLY);
    int count = 0;
    char **tmp;


    fstat(fd, &sb);
    map->map = malloc(sizeof(char) * (int)sb.st_size);
    read(fd, map->map, sb.st_size);
    map_without_size(&map);
    close(fd);
    for (int i = 0; map->map[i] != '\0'; i++)
        if (map->map[i] == '\n')
            count++;
    map->map_int = malloc(sizeof(int *) * (count + 1));
    tmp = my_str_to_word_array(map->map, '\n');
    for (count = 0; tmp[count] != NULL; count++)
        map->map_int[count] = malloc(sizeof(int) * (strlen(tmp[count]) + 1));
    map->map_int[count] = NULL;
    fill_map(&map);
}

int main(int ac, char **av)
{
    map_t map;

    if (ac != 2)
        return -1;
    init_map(av, &map);
    return(0);
}
