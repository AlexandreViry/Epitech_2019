/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <unistd.h>

void ai_turn(Match *play)
{
    int line = play->n;
    int match = 1;

    play->turn = 1;
    if (play->matches[line - 1] == 0)
        while (play->matches[line - 1] == 0)
            line--;
    if (play->matches[line - 1] > play->m)
        match = play->m;
    else if (play->matches[line - 1] > 1)
        match = play->matches[line - 1] -1;
    print_message(match, line);
    validated(play, line, match);
}

int start_the_game(Match *play)
{
    set_matches(play);
    while (play->count != 0) {
        display_board_game(play->board, play->n);
        my_putstr("Your turn:\n");
        set_line(play);
        if (count_stick(play) == 0)
            return (play->turn);
        if (play->ctrd == 0)
            return (0);
        display_board_game(play->board, play->n);
        ai_turn(play);
        if (count_stick(play) == 0)
            return (play->turn);
        if (play->ctrd == 0)
            return (0);
    }
    display_board_game(play->board, play->n);
    return (play->turn);
}

int end_game(int end, Match play)
{
    if (end == 2) {
        display_board_game(play.board, play.n);
        my_putstr("You lost, too bad...\n");
        return (2);
    }
    if (end == 1) {
        my_putstr( "I lost... snif... but ");
        my_putstr("I'll get you next time!!\n");
        return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    Match play;
    int end;

    if (ac != 3)
        return (84);
    play.ctrd = 1;
    play.n = my_atoi(av[1]);
    play.m = my_atoi(av[2]);
    play.count = play.n * play.n;
    play.board = create_board_game(play.n);
    end = start_the_game(&play);
    if (end == 0)
        return (0);
    end = end_game(play.turn, play);
    free(play.board);
    return (end);
}