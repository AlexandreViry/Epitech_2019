/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** contains all prototypes
*/

#include "struct.h"

void my_putchar(char c);
int my_atoi(char *str);
void display_board_game(char **board, int n);
char **create_border(char **board, int n);
char **init_i(char **board, int n);
char **create_board_game(int n);
int my_putstr(char *str);
int my_put_nbr(int nbr);
Match *set_line2(Match *play, int i);
Match *set_line(Match *play);
void set_line4(Match play, int i, int y);
void set_line3(Match play, int i, int y);
void analyse(char *buff, Match *play);
void set_matches(Match *play);
void print_message(int match, int line);
void ai_turn(Match *play);
Match *validated(Match *play, int i, int y);
int other_case(int nb);
int count_stick(Match *play);