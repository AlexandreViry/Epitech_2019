/*
** EPITECH PROJECT, 2020
** player1
** File description:
** player1 functions
*/

#include "include/my.h"

void handler5(int sig, siginfo_t *info, void *context)
{
    counter3(info->si_pid);
}

int player1(char *av)
{
    player_t player1;

    signalisation();
    map_create(&player1);
    map_editor(&player1, av);
    launcher();
    player1.pid = counter3(0) / 2;
    map_displayer(player1);
    start_the_game(&player1);
    return (0);
}