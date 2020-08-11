/*
** EPITECH PROJECT, 2020
** print_maze
** File description:
** display the maze
*/

#include "include/my.h"

void print_maze(char **maze, int x, int y)
{
    for (int i = 0; i != x - 1; i++)
        printf("%s\n", maze[i]);
    printf("%s", maze[x - 1]);
}