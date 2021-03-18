##
## EPITECH PROJECT, 2021
## Stumper2
## File description:
## Makefile
##

SRC =	main.c	\
	win.c	\
	winsecond.c	\
	structs.c	\
	game.c	\
	error.c	\
	errorsecond.c	\

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
