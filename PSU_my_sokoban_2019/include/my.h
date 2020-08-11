/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** macro with all prototypes
*/

#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char *str);
int my_strlen(char *str);
char *my_revstr(char *str);
char **move_right(char **map, int *coo);
char **move_left(char **map, int *coo);
char **move_bot(char **map, int *coo);
char **move_top(char **map, int *coo);
char **move_it(char **map, int c, int *coo);
char *recup(char *filepath);
int how_many_lines(char *buff);
char **convert(char *buff, char **map);
char **map_create(char *filepath);
int *search_p(char **map);
int victory(char **map, int size);
int *objective(char **map);
char **print_x(char **map, int *coo);
int the_longest(char *buff, int lines);
int *where_is_O(char **map);
char **set_o(char **map, int *coo);
int is_it_win(char **map);
int error(int ac, char **av);