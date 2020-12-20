##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	navy.c	\
		error_manager.c	\
		help.c	\
		check_format.c	\
		check_content.c	\
		host.c	\
		board_creation.c	\
		player_two.c	\
		attack.c \
		win_condition.c	\
		coordinates.c	\
		send_signal.c	\
		defense.c	\
		lib_functions.c

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