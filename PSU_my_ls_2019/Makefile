##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile everything
##

SRC	=	my_putstr.c	\
		main.c		\
		ls_1.c		\

OBJ	=       $(SRC:.c=.o)

NAME	=	my_ls

all:	$(NAME) clean

CPPFLAG: -Wall -Wextra -Iinclude

$(NAME):        $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	clear

fclean:		clean
	rm -f $(NAME)
	clear

re:	fclean all
