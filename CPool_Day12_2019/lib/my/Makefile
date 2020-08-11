##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile several functions 
##

SRC	=	my_find_prime_sup.c	\
		my_is_prime.c	\
		my_putstr.c	\
		my_showstr.c	\
		my_strcat.c	\
		my_str_isalpha.c	\
		my_str_isprintable.c	\
		my_strlowcase.c	\
		my_strncpy.c	\
		my_strupcase.c	\
		my_compute_power_rec.c	\
		my_getnbr.c	\
		my_putchar.c	\
		my_revstr.c	\
		my_sort_int_array.c	\
		my_strcmp.c	\
		my_str_islower.c	\
		my_str_isupper.c	\
		my_strncat.c	\
		my_str_showstr.c	\
		my_swap.c	\
		my_compute_square_root.c	\
		my_isneg.c	\
		my_put_nbr.c	\
		my_showmem.c	\
		my_strcapitalize.c	\
		my_strcpy.c	\
		my_str_isnum.c	\
		my_strlen.c	\
		my_strncmp.c	\
		my_strstr.c	

OBJ	=	$(SRC:.c=.o)

NAME	=	cat

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean	:
	rm -f $(OBJ)
fclean	: clean
	rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
