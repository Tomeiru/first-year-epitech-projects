##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/corewar.c	\
		src/error_manager.c	\
		src/flag_errors.c	\
		src/instru_one.c	\
		src/get_params.c	\
		src/str_lib_fct.c	\
		src/nbr_lib_fct.c	\
		src/op.c		\
		src/setup.c		\
		src/setup_champions.c	\

MAIN =	src/main.c

INC_PATH =	include

NAME =	corewar

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS)

all:	$(NAME)

debug:	CFLAGS += -g
debug:	fclean all
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS)

clean:
		rm -f $(OBJ) $(OBJMAIN)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all
