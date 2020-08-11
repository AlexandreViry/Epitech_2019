##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile everything
##

SRC	=	my_putchar.c	\
		if_nothing.c	\
		main.c		\

OBJ	=       $(SRC:.c=.o)

NAME	=	clean_str

all:	$(NAME) clean

CPPFLAG: -Wall -Wextra -Iinclude

$(NAME):        $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:     fclean all
