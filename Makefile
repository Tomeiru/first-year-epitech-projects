##
## EPITECH PROJECT, 2021
## Stumper3
## File description:
## Makefile
##

SRC =	main.c	\

NAME =	stumper3

OBJ = 	$(SRC:.c=.o)

CFLAGS += -g

$(NAME):	$(OBJ)
		@gcc -g -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
