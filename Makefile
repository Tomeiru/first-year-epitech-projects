##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	main.c	\
		rush.c	\
		sqcmp.c	\
		rush_one.c	\
		rush_two.c	\
		rush_three.c	\
		rush_four.c	\
		rush_five.c	\
		error.c	\
		second_print.c

INC_PATH=include

NAME =rush3

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

LIBS =	-L lib/my -lmy

$(NAME):	$(OBJ)
		@$(MAKE)	-s	-C	lib/my
		@gcc -g -o $(NAME) $(OBJ) $(LIBS) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ)
		@$(MAKE)	-s	-C	lib/my fclean

fclean:	clean
		rm -fr $(NAME)

re:	fclean all