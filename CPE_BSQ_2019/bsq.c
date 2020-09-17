/*
** EPITECH PROJECT, 2019
** BSQ
** File description:
** display the biggest square
*/

#include "include/my.h"

int search_zero_for_square(map_t *map, int y, int x)
{
    int count = 1;
    int i = 0;

    if (x >= map->size_length && y >= map->size_height - 1)
        return 0;
    if (map->map_int[y][x] == 0)
            return 0;
    for (; x + i < map->size_length && y +i < map->size_height && map->map_int
             [y + i][x] != 0 && map->map_int[y][x + i] != 0; i++, count++) {
        for (int z = 1; z < count && y + z < map->size_height &&
                 x + z < map->size_length; z++)
            if (map->map_int[y + z][x + i] == 0 ||
                map->map_int[y + i][x + z] == 0)
                return i;
    }
    return i;
}

void search_the_square(map_t *map)
{
    for (int i = map->y; i < map->y + map->greatest_value; i++)
        for (int z = map->x; z < map->x + map->greatest_value; z++)
            map->map_int[i][z] = 2;
}

void make_a_square(map_t *map)
{
    int x = 0;
    int y = 0;

    map->greatest_value = 0;
    for (int tmp = 0; y < map->size_height; x++) {
        if (x == map->size_length) {
            y++;
            x = 0;
            continue;
        }
        if (map->map_int[y][x] == 0)
            continue;
        tmp = search_zero_for_square(map, y, x);
        if (tmp > map->greatest_value) {
            map->greatest_value = tmp;
            map->y = y;
            map->x = x;
        }
    }
}

void converter(map_t *map)
{
    int x = 0;
    int y = 0;

    for (int i = 0; map->map[i] != '\0'; i++, x++) {
        if (map->map[i] == '\n') {
            x = 0;
            y++;
            i++;
        }
        if (map->map_int[y][x] != 0 && map->map_int[y][x] != 2)
            map->map[i] = '.';
        if (map->map_int[y][x] == 2)
            map->map[i] = 'x';
        if (map->map_int[y][x] == 0)
            map->map[i] = 'o';
    }
}

int main(int ac, char **av)
{
    map_t map;

    if (ac != 2)
        return -1;
    init_map(av, &map);
    make_a_square(&map);
    search_the_square(&map);
    converter(&map);
    printf("%s\n", map.map);
    return(0);
}
