##
## EPITECH PROJECT, 2019
## makefile
## File description:
## a
##

SRC	=	my_putchar.c	\
		my_putstr.c	\
		map_create.c	\
		move.c	\
		player.c	\
		main.c		\
		win_condition.c	\
		my_strlen.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       my_sokoban

all:    $(NAME)

CPPFLAG: -Wall -Wextra -Iinclude

$(NAME):        $(OBJ)
	gcc $(SRC) -o $(NAME) $(CPPFLAG) -lncurses -g3

clean:
	rm -f $(OBJ)
	clear

fclean:		clean
	rm -f $(NAME)
	clear

re:     fclean all
