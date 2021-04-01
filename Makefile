##
## EPITECH PROJECT, 2021
## Stumper3
## File description:
## Makefile
##

SRC =	main.c	\
	error.c	\
	setup.c	\
	write_numbers_first.c	\
	write_numbers_second.c	\

NAME =	crocus

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
