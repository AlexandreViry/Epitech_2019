##
## EPITECH PROJECT, 2019
## makefile
## File description:
## a
##

SRC	=	main.c	\
		sa.c	\
		pb.c	\

OBJ     =       $(SRC:.c=.o)

NAME    =       push_swap

all:	$(NAME)

CPPFLAG: -Wall -Wextra -Werror -Iinclude

$(NAME):        $(OBJ)
	gcc -g3 $(CPPFLAG) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:     fclean all
