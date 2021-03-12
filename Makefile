##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/ai_turn.c	\
		src/error.c	\
		src/ini_struct.c	\
		src/matchstick.c	\
		src/my_getnbr.c	\
		src/my_putchar.c	\
		src/my_putnbr.c	\
		src/my_revstr.c	\
		src/my_strlen.c	\
		src/once_per_turn.c	\
		src/user_turn.c	\

MAIN =	src/main.c

INC_PATH =	include

NAME =	matchstick

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ) $(OBJMAIN)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all