/*
** EPITECH PROJECT, 2020
** start2
** File description:
** playing functions for player 2
*/

#include "include/my.h"

void handler3(int Signal)
{
    counter3(1);
}

void handler4(int signal)
{
    counter3(0);
}

int signalisation2(void)
{
    struct sigaction Signal;
    struct sigaction Signal2;
    player_t player1;

    Signal.sa_handler = &handler3;
    Signal2.sa_handler = &handler4;
    sigaction(10, &Signal, 0);
    sigaction(12, &Signal2, 0);
}