/*
** EPITECH PROJECT, 2020
** player2
** File description:
** player2 functions
*/

#include "include/my.h"

int display_it(int av)
{
    if (kill(av, 10) == -1)
        return (-1);
    my_putstr("my_pid:\t");
    my_put_nbr(getpid());
    my_putchar('\n');
    kill(av, 10);
    my_putstr("successfully connected\n\n");
    return (0);
}

char *translate(int nb, player_t *player)
{
    int a;
    int b;

    nb = nb - 100;
    a = nb / 10;
    b = nb % 10;
}

int start_p2(player_t *player)
{
    player->win = 0;
    char *buff = malloc(sizeof(char) * 6);
    int str = recup(3);
    signalisation2();

    while (player->win == 0) {
        my_putstr("waiting for enemy's attack...");
        pause();
        str = recup(3);
        translate(str, player);
        my_putchar('\n');
        player->win = 1;
    }
}

int player2(int av, char *pos)
{
    player_t player2;

    if (display_it(av) == -1)
        return (84);
    player2.pid = av;
    kill(av, 10);
    map_create(&player2);
    map_editor(&player2, pos);
    map_displayer(player2);
    start_p2(&player2);
    return (0);
}