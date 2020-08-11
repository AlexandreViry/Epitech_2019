/*
** EPITECH PROJECT, 2020
** others
** File description:
** the rest of the functions
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <unistd.h>

Match *validated(Match *play, int i, int y)
{
    int p = 2 * play->n;

    for (; play->board[i][p] != '|'; p--) {
    }
    for (int a = p; a > p - y; a--)
        play->board[i][a] = ' ';
    play->matches[i - 1] = play->matches[i - 1] - y;
    return (play);
}

void analyse(char *buff, Match *play)
{
    for (int i = 0; buff[i] != '\n'; i++) {
        if (buff[i] > '9' || buff[i] < '0') {
            my_putstr("Error: invalid input (");
            my_putstr("positive number expected)\n");
            set_line(play);
        }
    }
}

void set_matches(Match *play)
{
    play->matches = malloc(sizeof(int) * play->n);
    int count = 1;

    for (int i = 0; i != play->n; i++) {
        play->matches[i] = count;
        count = count + 2;
    }
}

void print_message(int match, int line)
{
    my_putstr("AI's turn...\nAI removed ");
    my_put_nbr(match);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int count_stick(Match *play)
{
    int counter = 0;

    for (int i = 0; play->board[i] != NULL; i++)
        for (int y = 0; play->board[i][y] != '\0'; y++)
            if (play->board[i][y] == '|')
                counter++;
    return (counter);
}