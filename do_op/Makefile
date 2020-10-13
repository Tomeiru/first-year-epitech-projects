##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	doop.c	\
		error.c	\
		has_nbr.c	\
		is_op.c	\
		main.c	\
		my_get_sign.c

INC_PATH=include

NAME = do-op

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I. -I$(INC_PATH)

LIBS =	-L lib/my -lmy

$(NAME):	$(OBJ)
		@$(MAKE)	-s	-C	lib/my
		@gcc -o $(NAME) $(OBJ) $(LIBS) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ)
		@$(MAKE)	-s	-C	lib/my fclean

fclean:	clean
		rm -fr $(NAME)

re:	fclean all