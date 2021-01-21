##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	giantman.c	\
		error.c	\
		ppm_decompression.c	\

MAIN =	main.c

LIB_PATH	=	../lib/my/

INC_PATH =	include

NAME =	giantman

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

LIB	=	-L	$(LIB_PATH)	-lmy

CFLAGS	=	-I.	-I$(INC_PATH)	-Wall	-Wextra	-g

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc	-o	$(NAME)	$(OBJ)	$(OBJMAIN)	$(LIB)	$(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ) $(OBJMAIN)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all