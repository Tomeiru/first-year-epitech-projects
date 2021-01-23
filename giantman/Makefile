##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	giantman.c	\
		error.c	\
		lib_func.c	\
		ppm_decompression.c	\
		my_getnbr.c

MAIN =	main.c

INC_PATH =	include

NAME =	giantman

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