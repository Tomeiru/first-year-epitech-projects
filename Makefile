##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	pong.c	\
		error.c	\
		answer_calc.c

MAIN =	main.c

TESTS =	tests/file_reader_tests.c

INC_PATH =	include

NAME =	101pong

NAME_TEST =	exec_tests

EXEC_TEST = tests_run

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

OBJTEST = 	$(TESTS:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g -lm

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS)

$(NAME_TEST):	$(OBJ)	$(OBJTEST)
		@gcc -o $(NAME_TEST) $(OBJ) $(OBJTEST) $(CFLAGS) -lcriterion

all:	$(NAME)

$(EXEC_TEST):	fclean $(NAME_TEST)
		./$(NAME_TEST)

clean:	
		rm -f $(OBJ) $(OBJMAIN) $(OBJTEST)

fclean:	clean
		rm -fr $(NAME)
		rm -fr $(NAME_TEST)

re:	fclean all