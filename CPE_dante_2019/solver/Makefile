##
## EPITECH PROJECT, 2020
## Dante_solver
## File description:
## Makefile
##

NAME	=	solver

SRC	=	$(wildcard ./*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS	+= -ggdb -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm $(OBJ)

fclean:	clean
	rm $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
