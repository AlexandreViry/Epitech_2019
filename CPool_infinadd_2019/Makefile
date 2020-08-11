##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile several functions 
##

SRC	=	my_putstr.c	\
		my__putchar.c	\
		my_revstr.c	\
		my_strlen.c	\
		infin_add.c

OBJ	=	$(SRC:.c=.o)

NAME	=	infin_add

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rc libmy.a $(OBJ)
	cp libmy.a ../
	cp my.h ../../include
	gcc -o $(NAME) -L. -lmy

clean	:
	rm -f $(OBJ)
fclean	: clean
	rm -f $(NAME)
	rm -f libmy.a

re	:	fclean all

.PHONY	:	all clean fclean re
