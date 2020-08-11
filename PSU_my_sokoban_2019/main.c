/*
** EPITECH PROJECT, 2020
** main
** File description:
** main function
*/

#include "include/my.h"

int  print_guide(int ac, char **av)
{
    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            my_putstr("DESCRIPTION");
            my_putchar('\n');
            my_putstr("     map   file representing the warehouse map, ");
            my_putchar('\n');
            my_putstr("containing '#' for walls, ");
            my_putstr("          'P' for the player, 'X' for boxes and 'O'");
            my_putstr(" for storage locations.\n");
            return (0);
        }
        return (1);
    }
}

void print_it(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        printw(map[i]);
    }
}

int start_the_game(int ac, char **av, char *filepath)
{
    char **map = map_create(filepath);
    int c;
    int *coo_o = where_is_O(map);

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    while (1) {
        clear();
        print_it(map);
        c = getch();
        move_it(map, c, coo_o);
        if (c == 27)
        break;
        if (is_it_win(map) == 0)
            break;
    }
    endwin();
    return (0);
}

int main(int ac, char **av)
{
    if (error(ac, av) == 1)
        return (84);
    if (print_guide(ac, av) == 0)
        return (0);
    start_the_game(ac, av, av[1]);
}