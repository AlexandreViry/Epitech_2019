##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## We copy stuff
##

SRC	=	./lib/my/my_putchar.c			\
		./lib/my/which_is_longer.c		\
		./lib/my/my_isneg.c			\
		./lib/my/my_copy_strn.c			\
		./lib/my/my_put_nbr.c			\
		./lib/my/my_swap.c			\
		./lib/my/my_putstr.c			\
		./lib/my/my_putnstr.c			\
		./lib/my/my_strlen.c			\
		./lib/my/my_getnbr.c			\
		./lib/my/my_sort_int_array.c		\
		./lib/my/my_compute_power_rec.c		\
		./lib/my/my_compute_square_root.c	\
		./lib/my/my_is_prime.c			\
		./lib/my/my_find_prime_sup.c		\
		./lib/my/my_strcpy.c			\
		./lib/my/my_strncpy.c			\
		./lib/my/my_revstr.c			\
		./lib/my/my_strstr.c			\
		./lib/my/my_strcmp.c			\
		./lib/my/my_strncmp.c			\
		./lib/my/my_strupcase.c			\
		./lib/my/my_strlowcase.c		\
		./lib/my/my_strcapitalize.c		\
		./lib/my/my_str_isnum.c			\
		./lib/my/my_str_isalpha.c		\
		./lib/my/my_str_isupper.c		\
		./lib/my/my_str_islower.c		\
		./lib/my/my_str_isprintable.c		\
		./lib/my/my_showstr.c			\
		./lib/my/my_showmem.c			\
		./lib/my/my_strcat.c			\
		./lib/my/my_strncat.c			\
		./lib/my/my_memset.c			\
		./lib/my/my_strdup.c			\
		./lib/my/my_copy_str_skip.c		\
		./lib/my/my_replace_char.c		\
		./lib/my/my_int_to_str.c		\
		./lib/my/my_copy_segment.c		\
		./lib/my/my_put_in_seg.c		\
		./src/infinadd/InfinAdd.c		\
		./src/infinadd/addon_two.c		\
		./src/infinmul/infinmul.c		\
		./src/infinmul/neg_test.c		\
		./src/infinsub/infinsub.c		\
		./src/infindiv/infindiv.c		\
		./src/infinmod/infinmod.c		\
		./src/eval_expr/eval_expr.c		\
		./src/eval_expr/parenthesis.c		\
		./src/eval_expr/first_num.c		\
		./src/eval_expr/operations.c		\
		./test.c				\

OBJ     =       $(SRC:.c=.o)

NAME 	= 	calc

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(OBJ)
	gcc -o $(NAME) -L. -lmy -Wall -Wextra

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f libmy.a
	@rm -f *~
	clear

re:	fclean all
