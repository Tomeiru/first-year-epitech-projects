##
## EPITECH PROJECT, 2021
## Stumper2
## File description:
## Makefile
##

SRC =	main.c	\
	win.c	\
	structs.c	\
	game.c	\
	error.c	\

NAME =	connect4

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
