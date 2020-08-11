##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile several functions
##

SRC	=	./lib/my/my_putstr.c	\
		./lib/my/my_putchar.c	\
		./lib/my/my_revstr.c	\
		./lib/my/my_put_nbr.c	\
		./lib/my/my_strlen.c	\
		./lib/my/my_put_hexa.c	\
		./lib/my/my_put_hexa2.c	\
		./lib/my/my_put_octa.c	\
		./lib/my/my_put_binar.c	\
		./lib/my/my_put_pointer.c	\
		./lib/my/my_printf.c

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
