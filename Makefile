##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	countwords.c	\
	error.c	\
	my_strcmp.c	\

MAIN =	main.c

INC_PATH =	include

NAME =	countwords

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -Wall -Wextra -g

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ) $(OBJMAIN) $(OBJTEST)

fclean:	clean
		rm -fr $(NAME)
		rm -fr $(NAME_TEST)

re:	fclean all
