/*
** EPITECH PROJECT, 2020
** map_editor
** File description:
** put positions on the map
*/

#include "include/my.h"

char **sgl_to_dbl(char *buff)
{
    int count = 0;
    char **coo = malloc(sizeof(char *) * 5);

    for (int i = 0; i < 5; i++)
        coo[i] = malloc(sizeof(char) * 8);
    for (int i = 0; i < 4; i++)
        for (int y = 0; y < 8; y++) {
            coo[i][y] =  buff[count];
            count++;
        }
    return (coo);
}

player_t *same(player_t *player, char **coo, int i)
{
    int l = coo[i][2] - 65;
    int a = coo[i][3] - 49;
    int z = coo[i][6] - 49;
    char boat = coo[i][0];

    if (l != 0)
        l = 2 * l;
    for (int y = 0; y != boat - 48; y++) {
        player->map[a][l] = boat;
        a++;
    }
    return (player);
}

player_t *different(player_t *player, char **coo, int i)
{
    int a = coo[i][2] - 65;
    int z = coo[i][5] - 49;
    int n = coo[i][6] - 49;
    char boat = coo[i][0];

    if (a != 0)
        a = 2 * a;
    if (z != 0)
        z = 2 * z;
    for (int y = 0; y != boat - 48; y++) {
        player->map[n][a] = boat;
        a = a + 2;
    }
    return (player);
}

player_t *map_editor(player_t *player, char *path)
{
    int fd = open(path, O_RDONLY);
    char *buff = malloc(sizeof(char) * 33);
    char **coo;

    read(fd, buff, 31);
    coo = sgl_to_dbl(buff);
    for (int i = 0; i < 4; i++) {
        if (coo[i][2] == coo[i][5])
            same(player, coo, i);
        else
            different(player, coo, i);
    }
    return (player);
}