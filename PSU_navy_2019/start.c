/*
** EPITECH PROJECT, 2020
** start
** File description:
** start_the_game
*/

#include "include/my.h"

void convert(int i, int y, player_t *player)
{
    for (int count = 0; count < i; count++)
        kill(player->pid, 10);
    kill(player->pid, 12);
    for (int count = 0; count < y; count++)
        kill(player->pid, 10);
    kill(player->pid, 12);
    kill(player->pid, 12);
}

void send_it(char *buff, player_t *player)
{
    char a = buff[0];
    char b = buff[1];
    int y = '0';
    int i = 64;

    if (a > 'H' || a < 65  || b > '8' || b < '1') {
        my_putstr("wrong position");
        my_putchar('\n');
        free(buff);
        start_the_game(player);
    }
    if (buff[3] != '\0' && buff[3] != '\n') {
        my_putstr("wrong position");
        my_putchar('\n');
        free(buff);
        start_the_game(player);
    }
    i = a - i;
    y = b - y;
    convert(i, y, player);
}

int start_the_game(player_t *player)
{
    size_t size = 0;
    ssize_t read2;
    player->win = 0;
    char *buff = malloc(sizeof(char) * 6);

    while (player->win == 0) {
        my_putstr("attack:\t");
        if (read2 = getline(&buff, &size, stdin) < 0)
            return (0);
        send_it(buff, player);
        break;
    }
}