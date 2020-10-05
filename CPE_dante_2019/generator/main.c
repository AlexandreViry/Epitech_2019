/*
** EPITECH PROJECT, 2020
** generator
** File description:
** generate a perfect maze
*/

#include "./include/my.h"

char **maze_init(int lines, int column)
{
    char **maze;

    if (lines <= 0 || column <= 0) {
        printf("Positive integers only.");
        exit(84);
    }
    maze = malloc(sizeof(char *) * lines);
    for (int i = 0; i != lines; i++)
        maze[i] = malloc(sizeof(char) * (column + 1));
    return (maze);
}

char **maze_set(char **maze, int lines, int columns)
{
    for (int i = 0; i != lines; i++)
        for (int y = 0; y != columns; y++)
            maze[i][y] = 'X';
    maze[0][0] = '*';
    maze[lines - 1][columns - 1] = '*';
    for (int i = 0; i != lines; i++)
        maze[i][columns] = '\0';
    return (maze);
}

int main(int ac, char **av)
{
    char **maze = maze_init(atoi(av[1]), atoi(av[2]));
    board_t board;

    board.length = atoi(av[2]);
    board.hight = atoi(av[1]);
    maze_set(maze, atoi(av[1]), atoi(av[2]));
    from_map_top_cell_board(maze, &board);
    generating_maze(&board);
    print_board_with_char(board);
    print_board(board);
    printf("\n");
}
