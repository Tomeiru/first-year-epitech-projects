##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/generator.c	\
		src/error.c	\
		src/create_struct.c	\
		src/generate_perfect_maze.c	\
		src/check_possible_direction.c	\
		src/apply_direction.c	\
		src/linked_list_func.c

MAIN =	src/main.c

INC_PATH =	include

NAME =	generator

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
