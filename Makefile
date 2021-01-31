##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	mysh.c	\
		error.c	\
		lib_functions.c	\
		builtin_cd.c	\
		builtin_env_exit.c	\
		builtin_setenv.c	\
		builtin_unsetenv.c	\
		builtin.c	\
		get_input.c	\

MAIN =	main.c

INC_PATH =	include

NAME =	mysh

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