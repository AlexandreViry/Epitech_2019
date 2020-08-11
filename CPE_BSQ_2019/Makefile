##
## EPITECH PROJECT, 2019
## makefile
## File description:
## a
##

SRC	=	./lib/my/my_putchar.c	\
		./lib/my/my_put_nbr.c	\
		./BSQ.c

OBJ     =       $(SRC:.c=.o)

NAME    =       BSQ

all:    lib $(NAME) 

CPPFLAG: -Wall -Wextra -Iinclude 

$(NAME):        $(OBJ)
	gcc BSQ.c -o $(NAME) $(CPPFLAG)

clean:
	rm -f $(OBJ)
	clear

fclean:		clean
	rm -f $(NAME)
	clear

re:     fclean all
