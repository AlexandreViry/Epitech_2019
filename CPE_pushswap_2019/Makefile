##
## EPITECH PROJECT, 2019
## makefile
## File description:
## a
##

SRC	=	./lib/my/my_strlen.c	\
		./lib/my/my_atoi.c      \
                ./lib/my/my_putchar.c   \
                ./lib/my/my_put_nbr.c   \
		./lib/my/my_putstr.c	\
                is_it_ord.c             \
		sa.c			\
		sb.c			\
		ra.c			\
		pa.c			\
		algorithm.c		\
                main.c                  \

OBJ     =       $(SRC:.c=.o)

NAME    =       push_swap

all:    lib $(NAME)

CPPFLAG: -Wall -Wextra -Iinclude 

$(NAME):        $(OBJ)
	gcc $(SRC) -o $(NAME) $(CPPFLAG) -lncurses -g3

clean:
	rm -f $(OBJ)
	clear

fclean:		clean
	rm -f $(NAME)
	clear

re:     fclean all
