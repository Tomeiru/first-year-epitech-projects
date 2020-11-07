##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	file_reader.c	\
		bsq.c	\
		board_check.c	\
		algorithm.c	\

MAIN =	main.c

TESTS =	tests/file_reader_tests.c

INC_PATH =	include

NAME =	bsq

NAME_TEST =	bsq_final_tests

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

OBJTEST = 	$(TESTS:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

LIBS =	-L lib/my -lmy

$(NAME):	$(OBJ)	$(OBJMAIN)
		@$(MAKE)	-s	-C	lib/my
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(LIBS) $(CFLAGS)

$(NAME_TEST):	$(OBJ)	$(OBJTEST)
		@$(MAKE)	-s	-C	lib/my
		@gcc -o $(NAME_TEST) $(OBJ) $(OBJTEST) $(LIBS) $(CFLAGS) -lcriterion

all:	$(NAME)

tests:	$(NAME_TEST)

clean:	
		rm -f $(OBJ) $(OBJMAIN) $(OBJTEST)
		@$(MAKE)	-s	-C	lib/my fclean

fclean:	clean
		rm -fr $(NAME)
		rm -fr $(NAME_TEST)

re:	fclean all