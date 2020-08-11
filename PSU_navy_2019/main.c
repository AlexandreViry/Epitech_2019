/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include "include/my.h"

void launcher(void)
{
    my_putstr("my_pid:\t");
    my_put_nbr(getpid());
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n");
    my_putchar('\n');
    pause();
    my_putstr("enemy connected\n");
    my_putchar('\n');
}

void map_displayer(player_t player)
{
    map_display(player.map);
    my_putchar('\n');
    e_map_display(player.e_map);
    my_putchar('\n');
}

int who_is_playing(int ac)
{
    if (ac == 2)
        return (1);
    if (ac == 3)
        return (2);
    else
        return (84);
}

int signalisation(void)
{
    struct sigaction Signal;
    player_t player1;

    Signal.sa_flags = SA_SIGINFO;
    Signal.sa_sigaction = &handler5;
    sigaction(10, &Signal, NULL);
}

int main(int ac, char **av)
{
    int i = 0;

    if (error(ac, av) == 84)
        return (84);
    switch (who_is_playing(ac)) {
    case 1:
        i = player1(av[1]);
        break;
    case 2:
        i = player2(my_atoi(av[1]), av[2]);
        break;
    case 84:
        return (84);
    }
    return (0);
}