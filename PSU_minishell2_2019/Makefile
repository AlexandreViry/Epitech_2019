##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile everything
##

SRC	=	main.c		\
		env.c		\
		src/my_putchar.c	\
		src/my_strlen.c	\
		src/my_strcmp.c	\
		src/my_strcut.c	\
		src/my_atoi.c	\
		my_setenv.c	\
		cd.c			\
		src/my_strcat.c		\
		clearstring.c		\
		my_str_to_word_array.c	\
		search_path.c	\

OBJ	=       $(SRC:.c=.o)

NAME	=	mysh

CPPFLAGS	= -g3 -Wall -Wextra -Iinclude

all:	$(NAME)

$(NAME):        $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:     fclean all
