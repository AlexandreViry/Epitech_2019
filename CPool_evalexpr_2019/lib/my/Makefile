##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compil 	
##

SRC     =	my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_revstr.c	\
		my_strtol.c	\
		number2.c	\
		number.c	\
		summands.c	\
		difference.c	\
		quotient.c	\
		product.c	\
		modulo.c	\
		int_to_string.c

OBJ     =	$(SRC:.c=.o)

NAME    =	libmy.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean all
