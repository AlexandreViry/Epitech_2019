##
## EPITECH PROJECT, 2019
## makefile
## File description:
## a
##

SRC =	bsq.c		\
	my_str_to_word_array.c	\

OBJ = $(SRC:.c=.o)

NAME = BSQ

all: $(NAME)

CPPFLAG: -Wall -Wextra -Iinclude

$(NAME):        $(OBJ)
	gcc $(CPPFLAG) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)
	clear

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)

re:     fclean all
