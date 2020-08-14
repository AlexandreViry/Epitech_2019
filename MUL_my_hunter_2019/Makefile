##
## EPITECH PROJECT, 2019
## makefile
## File description:
## a
##

SRC	=	my_putstr.c		\
		test3.c			\
		test2.c			\
		graphical_test1.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       my_hunter

DIRECTORY       =       lib/my

all:    lib $(NAME)

CPPFLAG: -Wall -Wextra -Iinclude

lib: $(DIRECTORY)
	make -C $(DIRECTORY)

$(NAME):        $(OBJ)
	gcc $(SRC) -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
	rm -f $(OBJ)
	clear

fclean:		clean
	rm -f $(NAME)
	clear

re:     fclean all
