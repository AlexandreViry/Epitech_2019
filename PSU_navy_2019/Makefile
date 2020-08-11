##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile everything
##

SRC	=	main.c		\
		my_putchar.c	\
		my_atoi.c	\
		map_edit.c	\
		create_maps.c	\
		player1.c	\
		counter.c	\
		my_itoa.c	\
		start2.c	\
		start.c	\
		recup.c		\
		error.c	\
		player2.c	\

OBJ	=       $(SRC:.c=.o)

NAME	=	navy

CPPFLAG =  -Wall -Wextra -Wuninitialized -Iinclude

all:	$(NAME) clean

$(NAME):        $(OBJ)
	gcc -g3 -o $(NAME) $(OBJ) $(CPPFLAG)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:     fclean all
