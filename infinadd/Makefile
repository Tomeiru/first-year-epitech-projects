##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	calcadd.c	\
		error.c	\
		infinadd.c	\
		info.c	\
		main.c	\
		same_tenth.c	\
		use_longest.c

INC_PATH=include

NAME = infin_add

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra

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