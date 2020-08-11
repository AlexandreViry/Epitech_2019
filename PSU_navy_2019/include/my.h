/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** all prototypes
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include "struct.h"
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_put_nbr(int nb);
int other_case(int nb);
void my_putchar(char c);
int my_putstr(char *str);
int my_atoi(char *str);
void map_create(player_t *player);
void map_display(char **map);
int player1(char *av);
int player2(int av, char *pos);
void map_displayer(player_t player);
void launcher(void);
void handler(int Signal);
void handler2(int Signal);
int signalisation(void);
int counter(int i);
int counter2(int i);
int start_the_game(player_t *player);
char *my_itoa(int i);
int signalisation2(void);
int counter3(int i);
void handler5(int sig, siginfo_t *info, void *context);
player_t *map_editor(player_t *player, char *path);
void e_map_display(char **map);
int error(int ac, char **av);
char **sgl_to_dbl(char *str);
int who_is_playing(int ac);