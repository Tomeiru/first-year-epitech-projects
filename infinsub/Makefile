##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	../infinadd/calcadd.c	\
		../infinadd/error.c	\
		../infinadd/infinadd.c	\
		../infinadd/info.c	\
		main.c	\
		../infinadd/same_tenth.c	\
		../infinadd/use_longest.c	\
		infinsub.c	

INC_PATH=../infinadd/include

NAME = infin_sub

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

LIBS =	-L ../infinadd/lib/my -lmy

$(NAME):	$(OBJ)
		@$(MAKE)	-s	-C	../infinadd/lib/my
		@gcc -o $(NAME) $(OBJ) $(LIBS) $(CFLAGS)

all:	$(NAME)

clean:	
		rm -f $(OBJ)
		@$(MAKE)	-s	-C	../infinadd/lib/my fclean

fclean:	clean
		rm -fr $(NAME)

re:	fclean all