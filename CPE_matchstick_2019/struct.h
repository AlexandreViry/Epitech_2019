/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** structure used
*/

typedef struct Match Match;
struct Match
{
    int n;
    int m;
    int *matches;
    int count;
    char **board;
    int turn;
    int ctrd;
};
