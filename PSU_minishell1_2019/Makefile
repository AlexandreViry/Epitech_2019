##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile everything
##

SRC	=	main.c		\
		my_putchar.c	\
		my_strlen.c	\
		my_strcmp.c	\
		part2.c		\
		part3.c		\

OBJ	=       $(SRC:.c=.o)

NAME	=	mysh

CPPFLAGS	= -Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME):        $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:     fclean all
