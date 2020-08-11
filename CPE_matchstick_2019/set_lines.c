/*
** EPITECH PROJECT, 2020
** set_lines
** File description:
** all set lines functions
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>
#include <unistd.h>

void set_line4(Match play, int i, int y)
{
    if (y > play.m) {
        my_putstr("you cannot remove more than ");
        my_put_nbr(play.m);
        my_putstr(" matches per turn\n");
    }
    if (y > play.matches[i - 1]) {
        my_putstr("ERROR: not enough matches on ");
        my_putstr("this line\n");
    }
}

void set_line3(Match play, int i, int y)
{
    if (y > play.m || y > play.matches[i - 1]) {
        set_line4(play, i, y);
    }
    else if (y < 0 || y > 57 || y < 48)
        my_putstr("invalid input (positive number expected)\n");
    else if (y == 0)
        my_putstr("Error: you have to remove at least one match\n");
    set_line(&play);
}

Match *set_line2(Match *play, int i)
{
    size_t size = 0;
    ssize_t read2;
    char *buff = NULL;
    int y;

    my_putstr("Matches: ");
    read2 = getline(&buff, &size, stdin);
    my_putchar('\n');
    if (read2 < 0) {
        play->ctrd = 0;
        return (play);
    }
    y = my_atoi(buff);
    if (y > play->m || y > play->matches[i - 1] || y <= 0)
        set_line3(*play, i, y);
    else {
        play = validated(play, i, y);
    }
    return (play);
}

Match *set_line(Match *play)
{
    size_t len = 0;
    ssize_t read2;
    char *buff = NULL;
    int i;

    play->turn = 2;
    my_putstr("Line: ");
    read2 = getline(&buff, &len, stdin);
    if (read2 < 0) {
        play->ctrd = 0;
        return (play);
    }
    i = my_atoi(buff);
    analyse(buff, play);
    if (i > play->n || i <= 0)
        my_putstr("Error: this line is out of range\n");
    else if (play->matches[i - 1] == 0)
        my_putstr("Error: not enough matches on this line\n");
    else if (i > 0 && i <= play->n) {
        set_line2(play, i);
        if (play->ctrd == 0)
            return (play);
        return (play);
    }
    free(buff);
    buff = NULL;
    set_line(play);
    return (play);
}