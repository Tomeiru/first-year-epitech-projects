##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	solver.c	\
		error.c	\
		file_reader.c	\
		create_struct.c	\
		get_xy_value.c	\
		check_possible_direction.c	\
		linked_list_func.c	\
		apply_direction.c

MAIN =	main.c

INC_PATH =	include

NAME =	solver

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
