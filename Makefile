##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	change_linked_list.c	\
		check_win_or_lose.c	\
		condition_direction.c	\
		create_linked_list.c	\
		error.c	\
		file_reader.c	\
		ini_struct.c	\
		input_gestion.c	\
		map_str_to_map_arr.c	\
		my_sokoban.c	\
		run_game.c	\
		my_strcmp.c	\

MAIN =	main.c

INC_PATH =	include

NAME =	my_sokoban

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -lncurses -I. -I$(INC_PATH) -Wall -Wextra -g

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ) $(OBJMAIN)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all