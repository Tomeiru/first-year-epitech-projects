##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	main.c	\
		my_atoi.c	\
		eval_expr.c	\
		error.c	\
		infin_tests.c

INC_PATH =	include

NAME =	calc

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