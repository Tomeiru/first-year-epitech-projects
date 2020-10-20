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

LIB_NAME	=	-L lib/my -lmy

$(NAME):$(OBJ)
		$(MAKE)	-s	-C	lib/my
		@gcc -o $(NAME) $(OBJ) $(LIB_NAME) $(HEAD)

all:	$(NAME)

clean:
		rm -f $(OBJ)
		@$(MAKE)	-s	-C	lib/my fclean

fclean:	clean
		rm -fr $(NAME)

re:	fclean all