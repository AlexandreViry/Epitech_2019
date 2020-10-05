##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile everything
##

SRC	=	main.c	\
		print_maze.c	\
		from_map_to_cell_board.c	\
		generating_maze.c	\
		contamination.c	\

OBJ	=       $(SRC:.c=.o)

NAME	=	generator

all:	$(NAME) clean

CPPFLAG: -Wall -Wextra -Iinclude

$(NAME):        $(OBJ)
	gcc -g3 -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:     fclean all
