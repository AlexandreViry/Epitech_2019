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
		product.c	\
		src/my_compute_power_it.c	\
		src/clear_string.c	\
		division.c		\
		infin_sub.c		\

OBJ	=       $(SRC:.c=.o)

NAME	=	bistro-matic

CPPFLAGS	= -Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME):        $(OBJ)
	gcc -g3 -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:     fclean all
