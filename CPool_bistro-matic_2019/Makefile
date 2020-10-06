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
		my_str_to_word_array.c	\
		src/my_revstr.c	\
		parentheses.c	\
		src/my_strcat.c	\
		eval_expr.c	\
		product.c	\
		modulo.c		\
		src/clear_string.c	\
		src/errors.c		\
		division.c		\
		src/power_of_ten.c	\
		infin_sub.c		\
		src/analyse_string.c	\

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
