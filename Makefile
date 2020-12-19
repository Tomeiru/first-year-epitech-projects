##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	navy.c	\
		error.c	\
		my_swap.c	\
		board_creation.c	\
		host.c	\
		player_two.c	\
		my_getnbr.c	\
		attack.c

MAIN =	main.c

INC_PATH =	include

NAME =	navy

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

LIBS =	-L lib/my -lmy

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ) $(OBJMAIN)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all