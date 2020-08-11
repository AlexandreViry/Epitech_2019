##
## EPITECH PROJECT, 2019
## makefile
## File description:
## compile everything
##

SRC	=	display_window.c	\
		animation_char.c	\
		paralax_part1.c		\
		paralax_part2.c		\
		paralax_part3.c		\
		initialisation.c	\
		main_menu.c		\
		masterchief.c		\
		masterchief2.c		\
		read_map.c		\
		my_strcmp.c		\
		add_on.c		\
		end_game.c		\
		main.c	\

OBJ	=       $(SRC:.c=.o)

NAME	=	my_runner

all:	$(NAME) clean

CPPFLAG: -Wall -Wextra -Iinclude

$(NAME):        $(OBJ)
	gcc $(SRC) -o $(NAME) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:     fclean all
