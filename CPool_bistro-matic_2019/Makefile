##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile everything
##

SRC	=	main.c		\
		infin_add.c	\
		src/my_putstr.c	\
		src/my_putchar.c	\
		src/my_revstr.c	\

OBJ	=       $(SRC:.c=.o)

NAME	=	infin_add

CPPFLAGS	= -Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME):        $(OBJ)
	gcc -g3 -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:     fclean all
