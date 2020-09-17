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
        return -1;
    if (map->map_int[y][x] == 0)
            return -1;
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
        if (tmp > map->greatest_value)
            map->greatest_value = tmp;
    }
    printf("%d\n", map->greatest_value);
}

int main(int ac, char **av)
{
    map_t map;

    if (ac != 2)
        return -1;
    init_map(av, &map);
    make_a_square(&map);
    for (int i = 0; i < map.size_height; i++) {
        for (int y = 0; y < map.size_length - 1; y++)
            printf("%d",map.map_int[i][y]);
        printf("\n");
    }
    return(0);
}
