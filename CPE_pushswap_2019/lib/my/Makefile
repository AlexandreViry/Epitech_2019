##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile several functions 
##

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_strlen.c	\
		my_atoi.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CPPFLAG	=	-Iinclude -Wall -Wextra

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean	:
	rm -f $(OBJ)
	clear

fclean	: clean
	rm -f $(NAME)
	clear

re	:	fclean all

.PHONY	:	all clean fclean re
