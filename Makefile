##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	architect.c	\
		error.c	\
		answer_calc.c	\
		double_to_matrix.c	\
		modifier_matrix.c

MAIN =	main.c

INC_PATH =	include

NAME =	102architect

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g -lm

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ) $(OBJMAIN) $(OBJTEST)

fclean:	clean
		rm -fr $(NAME)
		rm -fr $(NAME_TEST)

re:	fclean all