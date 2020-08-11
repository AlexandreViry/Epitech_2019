##
## EPITECH PROJECT, 2019
## makefile
## File description:
## a
##

SRC	=	main.c	\
		newstring.c	\
		calcul.c	\
		getmin.c	\
		getmax.c

OBJ     =       $(SRC:.c=.o)

NAME    =       eval_expr

DIRECTORY       =       lib/my

all:    lib $(NAME) clean

lib: $(DIRECTORY)
	make -C $(DIRECTORY)

$(NAME):        $(OBJ)
	gcc -o $(NAME) $(OBJ) -L. lib/my/libmy.a

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:     fclean all
