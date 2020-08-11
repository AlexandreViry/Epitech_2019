##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile everything
##

SRC	=	main.c		\
		my_atoi.c	\
		my_putchar.c	\
		map_create.c	\
		set_lines.c	\
		others.c	\

OBJ	=       $(SRC:.c=.o)

NAME	=	matchstick

CPPFLAGS	= -Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME):        $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:     fclean all
