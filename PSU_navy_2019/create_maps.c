/*
** EPITECH PROJECT, 2020
** map_creator
** File description:
** create the two maps
*/

#include "include/my.h"

char **put_dot(char **map)
{
    for (int i = 0; i < 8; i++) {
        for (int y = 0; y <= 15; y++) {
            map[i][y] = '.';
            y++;
            map[i][y] = ' ';
        }
        map[i][16] = '\0';
    }
    return (map);
}

char **map_load(char **map)
{
    map = put_dot(map);
    return (map);
}

void map_display(char **map)
{
    int y = 1;

    my_putstr("my positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");

    for (int i = 0; i < 8; i++) {
        my_put_nbr(y);
        my_putchar('|');
        my_putstr(map[i]);
        my_putchar('\n');
        y++;
    }
}

void e_map_display(char **map)
{
    int y = 1;

    my_putstr("enemy's positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");

    for (int i = 0; i < 8; i++) {
        my_put_nbr(y);
        my_putchar('|');
        my_putstr(map[0]);
        my_putchar('\n');
        y++;
    }
}

void map_create(player_t *player)
{
    player->map = malloc(sizeof(char *) * 11);
    player->e_map = malloc(sizeof(char *) * 11);

    for (int i = 0; i != 11; i++)
        player->map[i] = malloc(sizeof(char) * 17);
    for (int i = 0; i != 11; i++)
        player->e_map[i] = malloc(sizeof(char) * 17);
    player->map = map_load(player->map);
    player->e_map = map_load(player->e_map);
}