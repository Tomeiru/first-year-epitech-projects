##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compiles project, lib and include folder
##

SRC	=	

OBJ	=	$(SRC:.c=.o)

INC_PATH	=	include

NAME	=	infin_add

HEAD	=	-I. -I$(INC_PATH) -Wall -Wextra

$(NAME):$(OBJ)
		@gcc -o $(NAME) $(OBJ) $(HEAD)

all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all