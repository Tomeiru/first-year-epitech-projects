##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	do_op/doop.c	\
		do_op/error.c	\
		do_op/has_nbr.c	\
		do_op/is_op.c	\
		do_op/main.c	\
		do_op/my_get_sign.c

INC_PATH=include

NAME = do-op

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I. -I$(INC_PATH)

LIBS =	-L ./lib/my -lmy

$(NAME):	$(OBJ)
		@$(MAKE)	-s	-C	lib/my
		@gcc -o $(NAME) $(OBJ) $(LIBS) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ)
		@$(MAKE)	-s	-C	lib/my fclean

fclean:	clean
		rm -fr $(NAME)

re: fclean all