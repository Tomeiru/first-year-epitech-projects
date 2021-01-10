##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	program/game.c	\
		program/ini_struct.c	\
		program/load_files.c	\
		program/game_forth.c	\
		program/game_second.c	\
		program/game_third.c	\
		program/game_fifth.c	\
		program/utils.c

MAIN =	program/main.c

INC_PATH =	include

NAME =	my_runner

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

LIBS =	-lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -L. -lmy

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(LIBS) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ) $(OBJMAIN) $(OBJTEST)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all