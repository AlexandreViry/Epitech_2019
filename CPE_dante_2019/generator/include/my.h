/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** all prototypes
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct board_s {
    int length;
    int hight;
    int **cell_board;
    int actual_value;
} board_t;


void print_maze(char **maze, int x, int y);
void print_board(board_t board);
void from_map_top_cell_board(char **map, board_t *board);
void generating_maze(board_t *board);
void print_board_with_char(board_t board);
void contamination(board_t *board);
