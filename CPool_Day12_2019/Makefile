##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile several functions
##

SRC     =       ../lib/my/Makefile
OBJ     =       $(SRC:.c=.o)

NAME    =       cat

all     :       $(NAME)

$(NAME) :       $(OBJ)
        ar rc $(NAME) $(OBJ)

clean   :
        rm -f $(OBJ)
fclean  : clean
        rm -f $(NAME)

re      :       fclean all

.PHONY  :       all clean fclean re
